#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QMainWindow>
#include <QCheckBox>
#include <QDebug>
#include <QComboBox>
#include <QMessageBox>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    sniffer(new PacketSniffer(this)),
    packetSeries(new QLineSeries()),
    trafficChart(new QChart()),
    axisX(new QValueAxis()),
    axisY(new QValueAxis()),
    graphTimer(new QTimer(this))
    {
    ui->setupUi(this);
        ui->saveButton->setStyleSheet(
            "QPushButton { background-color: #007bff; color: white; font-weight: bold; "
            "padding: 8px; border-radius: 6px; border: 1px solid #0056b3; }"
            "QPushButton:hover { background-color: #0069d9; }"
            "QPushButton:pressed { background-color: #0062cc; }"
            "QPushButton:disabled { background-color: #6c757d; border: 1px solid #5a6268; }"
            );
        connect(ui->deviceComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::onDeviceSelected);
        setupCaptureConstraints();
        hexDumpView = new QTextEdit(this);
        hexDumpView->setFont(QFont("Courier New", 10));
        hexDumpView->setReadOnly(true);
        ui->hexDumpLayout->addWidget(hexDumpView);
        updateTimer = new QTimer(this);
        updateTimer->setSingleShot(true);
        updateTimer->setInterval(100);

        connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateDelayedHexDump);
        trafficChart->addSeries(packetSeries);
        trafficChart->legend()->hide();
        trafficChart->setTitle("Packets per Second");

        axisX->setRange(0, 60);
        axisX->setTitleText("Time (s)");

        axisY->setRange(0, 50);
        axisY->setTitleText("Packets");

        trafficChart->addAxis(axisX, Qt::AlignBottom);
        trafficChart->addAxis(axisY, Qt::AlignLeft);
        packetSeries->attachAxis(axisX);
        packetSeries->attachAxis(axisY);
        ui->trafficChartView->setChart(trafficChart);

    populateDeviceList();

    // Connect signals and slots
    connect(sniffer, &PacketSniffer::packetCaptured, this, &MainWindow::updatePacketTable);
    connect(sniffer, &PacketSniffer::captureStarted, this, &MainWindow::onCaptureStarted);
    connect(sniffer, &PacketSniffer::captureError, this, &MainWindow::onCaptureError);
    connect(graphTimer, &QTimer::timeout, this, &MainWindow::updateTrafficGraph);
    connect(ui->tcpCheckBox, &QCheckBox::toggled, this, &MainWindow::onProtocolFilterChanged);
    connect(ui->udpCheckBox, &QCheckBox::toggled, this, &MainWindow::onProtocolFilterChanged);
    connect(ui->dnsCheckBox, &QCheckBox::toggled, this, &MainWindow::onProtocolFilterChanged);
    connect(ui->quicCheckBox, &QCheckBox::toggled, this, &MainWindow::onProtocolFilterChanged);
    connect(ui->tlsCheckBox, &QCheckBox::toggled, this, &MainWindow::onProtocolFilterChanged);
    connect(ui->allCheckBox, &QCheckBox::toggled, this, &MainWindow::onProtocolFilterChanged);
    connect(ui->addIpButton, &QPushButton::clicked, this, &MainWindow::onAddIpFilterClicked);
    connect(ui->removeIpButton, &QPushButton::clicked, this, &MainWindow::onRemoveIpFilterClicked);
    connect(ui->browseButton, &QPushButton::clicked, this, &MainWindow::onBrowseButtonClicked);
    ui->startButton->setCheckable(true);
    connect(ui->packetTable, &QTableWidget::itemSelectionChanged,this, &MainWindow::onPacketSelected);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::toggleCapture);
    connect(ui->packetTable, &QTableWidget::itemSelectionChanged, this, [this]() {
        QList<QTableWidgetItem*> items = ui->packetTable->selectedItems();
        if (!items.isEmpty()) {
            int row = items.first()->row();
            const auto& packets = sniffer->getCapturedPackets();
            if (row < packets.size()) {
                const auto& packet = packets[row];
                updateHexDumpView(packet.data.data(), packet.data.size());
            }
        }
    });
    ui->startButton->setStyleSheet(
        "QPushButton { background-color: #28a745; color: white; font-size: 16px; font-weight: bold; padding: 10px; border-radius: 8px; border: 2px solid #218838; }"
        "QPushButton:hover { background-color: #218838; }"
        "QPushButton:pressed { background-color: #1e7e34; }"
        "QPushButton:checked { background-color: #dc3545; border: 2px solid #c82333; }"
        "QPushButton:checked:hover { background-color: #c82333; }"
        "QPushButton:checked:pressed { background-color: #bd2130; }"
        );

    ui->packetTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Auto-select best device
    ui->deviceComboBox->insertItem(0, "Auto-select best device");
    ui->deviceComboBox->setCurrentIndex(0);

    // Status bar
    statusBar()->showMessage("Ready - Select device or use auto-detection");
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);
    connect(sniffer, &PacketSniffer::captureStarted, this, [this]() {
        ui->saveButton->setEnabled(false);
    });

    connect(sniffer, &PacketSniffer::captureError, this, [this]() {
        ui->saveButton->setEnabled(true);
    });
    // Initialize save button state
    ui->saveButton->setEnabled(false);


    // Setup the live protocol distribution graph
    setupGraph();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::populateDeviceList() {
    ui->deviceComboBox->clear();
    deviceData.clear();


    QList<NetworkInterface> devices = PacketSniffer::getAllDevices();
    for (const auto& device : devices) {
        QString displayText;

        displayText = device.friendlyName;

        ui->deviceComboBox->addItem(displayText);
        deviceData.append(device);
    }

    if (deviceData.isEmpty()) {
        ui->deviceComboBox->addItem("No devices found");
    }
}

void MainWindow::toggleCapture() {
    if (ui->startButton->isChecked()) {
        capturedPacketsCount = 0;
        capturedBytesCount = 0;
        int deviceIndex = ui->deviceComboBox->currentIndex();
        if (deviceIndex == 0) {
            sniffer->setDeviceName("");
        } else if (deviceIndex > 0 && deviceIndex <= deviceData.size()) {
            sniffer->setDeviceName(deviceData[deviceIndex - 1].name);
        } else {
            QMessageBox::warning(this, "Error", "Please select a valid network interface");
            ui->startButton->setChecked(false);
            return;
        }
        startCapture();
        ui->startButton->setText("Stop");
        statusBar()->showMessage("Starting capture...");
        graphTimer->start(1000);
        ui->saveButton->setEnabled(false);
    } else {
        stopCapture();
        ui->startButton->setText("Start");
        statusBar()->showMessage("Capture stopped");
        graphTimer->stop();
        ui->saveButton->setEnabled(true);
    }
}

void MainWindow::startCapture() {
    if (!sniffer->isRunning()) {
        sniffer->start();
    }
}

void MainWindow::stopCapture() {
    sniffer->stopCapture();
    sniffer->wait();
}
void MainWindow::updateNetworkInfo(const NetworkInterface &Interface) {
    ui->l1->setText(Interface.friendlyName);
    ui->l2->setText(Interface.ipAddress);
    ui->macaddress->setText(Interface.macAddress);
}

void MainWindow::onCaptureStarted(QString deviceName) {
    statusBar()->showMessage("Capturing on: " + deviceName);
    for (int i = 0; i < deviceData.size(); i++) {
        if (deviceData[i].name == deviceName) {
            ui->deviceComboBox->setCurrentIndex(i + 1);
            break;
        }
    }
    ui->saveButton->setEnabled(false);
}

void MainWindow::onCaptureError(QString errorMessage) {
    QMessageBox::warning(this, "Capture Error", errorMessage);
    ui->startButton->setChecked(false);
    ui->startButton->setText("Start");
    statusBar()->showMessage("Capture failed: " + errorMessage);
    ui->saveButton->setEnabled(true);

}

void MainWindow::onProtocolFilterChanged() {
    QStringList allowed = getSelectedProtocols();

    for (int i = 0; i < ui->packetTable->rowCount(); ++i) {
        QString rowProtocol = ui->packetTable->item(i, 6)->data(Qt::UserRole).toString();
        bool show = allowed.isEmpty() || allowed.contains(rowProtocol);
        ui->packetTable->setRowHidden(i, !show);
    }
}
QStringList MainWindow::getSelectedProtocols() {
    if (ui->allCheckBox->isChecked()) {
        return {"TCP","UDP","DNS","QUIC","TLS"}; // Empty = no filtering, show all
    }
    QStringList selected;

    if (ui->tcpCheckBox->isChecked()) selected << "TCP";
    if (ui->udpCheckBox->isChecked()) selected << "UDP";
    if (ui->dnsCheckBox->isChecked()) selected << "DNS";
    if (ui->quicCheckBox->isChecked()) selected << "QUIC";
    if (ui->tlsCheckBox->isChecked()) selected << "TLS";

    return selected;
}
void MainWindow::onAddIpFilterClicked() {
    QString ip = QString("%1.%2.%3.%4")
    .arg(ui->ipOctet1->text())
        .arg(ui->ipOctet2->text())
        .arg(ui->ipOctet3->text())
        .arg(ui->ipOctet4->text());

    if (ip.contains("..") || ip.contains("..")||ip[0]=='.'||ip[ip.size()-1]=='.') {
        QMessageBox::warning(this, "Invalid IP", "Please enter all four octets.");
        return;
    }

    IPFilterEntry::MatchType matchType;
    if (ui->sourceCheckBox->isChecked()) matchType = IPFilterEntry::Source;
    else if (ui->destinationCheckBox->isChecked()) matchType = IPFilterEntry::Destination;
    else if (ui->eitherCheckBox->isChecked()) matchType = IPFilterEntry::Either;
    else {
        QMessageBox::warning(this, "Select Filter", "Please select a source/destination filter.");
        return;
    }

    IPFilterEntry entry = { ip, matchType };
    ipFilterList.append(entry);
    ui->ipListWidget->addItem(ip + (matchType == IPFilterEntry::Source ? " (src)" :
                                        matchType == IPFilterEntry::Destination ? " (dst)" : " (either)"));
    onProtocolFilterChanged();
}

void MainWindow::onRemoveIpFilterClicked() {
    int row = ui->ipListWidget->currentRow();
    if (row >= 0 && row < ipFilterList.size()) {
        ipFilterList.removeAt(row);
        delete ui->ipListWidget->takeItem(row);
        onProtocolFilterChanged();
    }
}

bool matchesIPFilter(const QString &srcIP, const QString &destIP, const QList<IPFilterEntry> &filters) {
    if (filters.isEmpty()) return true;
    for (const auto &entry : filters) {
        if ((entry.matchType == IPFilterEntry::Source && entry.ip == srcIP) ||
            (entry.matchType == IPFilterEntry::Destination && entry.ip == destIP) ||
            (entry.matchType == IPFilterEntry::Either && (entry.ip == srcIP || entry.ip == destIP))) {
            return true;
        }
    }
    return false;
}
void MainWindow::onFixedIpFilterChanged() {
    onProtocolFilterChanged();
}
void MainWindow::updatePacketTable(QString srcMac, QString destMac, QString srcIP, QString destIP, QString protocol, int length, QString info) {
    QStringList allowedProtocols = getSelectedProtocols();
    if (!allowedProtocols.contains(protocol)) {
        return;
    }
    if (!matchesIPFilter(srcIP, destIP, ipFilterList)) return;
    int row = ui->packetTable->rowCount();
    ui->packetTable->insertRow(row);
    const auto& packets = sniffer->getCapturedPackets();
    if (!packets.isEmpty()) {
        const auto& packet = packets.last();
        updateHexDumpView(packet.data.data(), packet.data.size());
    }
    ui->packetTable->setItem(row, 0, new QTableWidgetItem(srcMac));
    ui->packetTable->setItem(row, 1, new QTableWidgetItem(destMac));
    ui->packetTable->setItem(row, 2, new QTableWidgetItem(srcIP));
    ui->packetTable->setItem(row, 3, new QTableWidgetItem(destIP));
    ui->packetTable->setItem(row, 4, new QTableWidgetItem(protocol));
    ui->packetTable->setItem(row, 5, new QTableWidgetItem(QString::number(length)));

    QTableWidgetItem *infoItem = new QTableWidgetItem(info);
    infoItem->setData(Qt::UserRole, protocol);
    ui->packetTable->setItem(row, 6, infoItem);

    onProtocolFilterChanged();
    ui->packetTable->scrollToBottom();

    protocolCounts[protocol]++;
    totalPackets++;
    packetsThisSecond++;
    // Check if we should stop capturing based on constraints
    checkCaptureConstraints(length);
}

void MainWindow::setupGraph() {
    chart = new QChart();
    series = new QBarSeries();
    chart->addSeries(series);
    chart->setTitle("Protocol Distribution (%)");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout->addWidget(chartView);

    graphUpdateTimer = new QTimer(this);
    connect(graphUpdateTimer, &QTimer::timeout, this, &MainWindow::updateGraph);
    graphUpdateTimer->start(10000);
}
void MainWindow::updateTrafficGraph() {
    timeCounter++;
    packetSeries->append(timeCounter, packetsThisSecond);

    if (packetSeries->count() > 60) {
        packetSeries->removePoints(0, packetSeries->count() - 60);
        axisX->setRange(timeCounter - 60, timeCounter);
    }

    if (packetsThisSecond > axisY->max()) {
        axisY->setMax(packetsThisSecond + 10);
    }

    if (packetsThisSecond > 40) {
        showAlert("⚠️ High traffic detected: " + QString::number(packetsThisSecond) + " packets/sec");
    }

    packetsThisSecond = 0;
}

void MainWindow::showAlert(const QString &message) {
    QMessageBox::warning(this, "Suspicious Traffic Detected", message);
}
void MainWindow::onDeviceSelected(int index) {
    if (index <= 0 || index - 1 >= deviceData.size()) {
        ui->l1->clear();
        ui->l2->clear();
        ui->macaddress->clear();
        return;
    }

    updateNetworkInfo(deviceData[index - 1]);
}
void MainWindow::onBrowseButtonClicked() {
    QString directory = QFileDialog::getExistingDirectory(
        this,
        tr("Select Export Location"),
        QDir::homePath(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
        );

    if (!directory.isEmpty()) {
        ui->savingPathLineEdit->setText(directory);
        updateDiskInformation(directory);
    }
}

void MainWindow::updateDiskInformation(const QString &path) {
    if (path.isEmpty()) {
        return;
    }

    QStorageInfo storage(path);
    if (!storage.isValid() || !storage.isReady()) {
        ui->diskCapacityLineEdit->setText("N/A");
        ui->diskSpaceLineEdit->setText("N/A");
        ui->diskUsageLineEdit->setText("N/A");
        return;
    }

    // Calculate disk information
    qint64 totalBytes = storage.bytesTotal();
    qint64 availableBytes = storage.bytesAvailable();
    qint64 usedBytes = totalBytes - availableBytes;

    double totalGB = totalBytes / (1024.0 * 1024.0 * 1024.0);
    double availableGB = availableBytes / (1024.0 * 1024.0 * 1024.0);
    double usedGB = usedBytes / (1024.0 * 1024.0 * 1024.0);

    int usagePercentage = (int)(100.0 * usedBytes / totalBytes);

    ui->diskCapacityLineEdit->setText(QString("%1 GB").arg(totalGB, 0, 'f', 2));
    ui->diskSpaceLineEdit->setText(QString("%1 GB Available").arg(availableGB, 0, 'f', 2));
    ui->diskUsageLineEdit->setText(QString("%1 GB Used (%2%)").arg(usedGB, 0, 'f', 2).arg(usagePercentage));
}


QString MainWindow::formatHexByte(u_char byte) {
    return QString("%1").arg(byte, 2, 16, QChar('0')).toUpper();
}

QString MainWindow::formatAsciiChar(u_char byte) {
    if (byte >= 32 && byte <= 126) {
        return QString(QChar(byte));
    }
    return QString(".");
}

QString MainWindow::createHexDump(const u_char *packet, int length) {
    QString output;
    const int BYTES_PER_LINE = 16;
    for (int offset = 0; offset < length; offset += BYTES_PER_LINE) {
        output += QString("%1  ").arg(offset, 4, 16, QChar('0')).toUpper();

        QString hexPart;
        QString asciiPart;
        for (int i = 0; i < BYTES_PER_LINE; i++) {
            if (offset + i < length) {
                u_char byte = packet[offset + i];
                hexPart += formatHexByte(byte) + " ";
                asciiPart += formatAsciiChar(byte);
                if (i == 7) {
                    hexPart += " ";
                }
            } else {
                hexPart += "   ";
                asciiPart += " ";
            }
        }
        output += hexPart + "  " + asciiPart + "\n";
    }
    return output;
}

void MainWindow::updateHexDumpView(const u_char *packet, int length) {
    QString hexDump = createHexDump(packet, length);
    hexDumpView->setText(hexDump);
}

void MainWindow::onPacketSelected() {
    if (!hexDumpView) {
        qDebug() << "Error: hexDumpView is not initialized";
        return;
    }

    QList<QTableWidgetItem*> selectedItems = ui->packetTable->selectedItems();
    if (selectedItems.isEmpty()) {
        hexDumpView->setText("Select a packet to view hex dump");
        return;
    }

    selectedRow = selectedItems.first()->row();
    hexDumpView->setText("Loading packet data...");
    updateTimer->start();
}
void MainWindow::updateDelayedHexDump() {
    const auto& packets = sniffer->getCapturedPackets();

    if (selectedRow >= 0 && selectedRow < packets.size()) {
        const auto& packet = packets[selectedRow];
        if (!packet.data.empty()) {
            updateHexDumpView(
                packet.data.data(),
                packet.data.size()
                );
        } else {
            hexDumpView->setText("No data available for this packet");
        }
    }
}

void MainWindow::updateSaveButtonState() {
    ui->saveButton->setEnabled(!sniffer->isRunning());
}
void MainWindow::updateGraph() {
    series->clear();
    QStringList protocols = protocolCounts.keys();
    QBarSet *set = new QBarSet("Protocols");
    QStringList categories;

    for (const QString &protocol : protocols) {
        int count = protocolCounts.value(protocol, 0);
        double percentage = (totalPackets > 0) ? (count * 100.0 / totalPackets) : 0;
        *set << percentage;
        categories << protocol;
    }

    series->append(set);

    QBarCategoryAxis *axisX = qobject_cast<QBarCategoryAxis*>(chart->axisX());
    if (axisX) {
        axisX->clear();
        axisX->append(categories);
    }
}
void MainWindow::onSaveButtonClicked() {
    if (sniffer->isRunning()) {
        QMessageBox::warning(this, "Cannot Save",
                             "Please stop the packet capture before saving data.");
        return;
    }
    QString savePath = ui->savingPathLineEdit->text();
    if (savePath.isEmpty()) {
        savePath = QDir::homePath();
    }

    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss");

    // Save CSV
    QString csvFilePath = QFileDialog::getSaveFileName(
        this,
        "Save Packet Capture as CSV",
        QDir::cleanPath(savePath + QDir::separator() + "packet_capture_" + timestamp + ".csv"),
        "CSV Files (*.csv);;Text Files (*.txt);;All Files (*)");

    if (!csvFilePath.isEmpty()) {
        savePacketsToCSV(csvFilePath);
    }

    // Save PCAP
    QString pcapFilePath = QFileDialog::getSaveFileName(
        this,
        "Save Packet Capture as PCAP",
        QDir::cleanPath(savePath + QDir::separator() + "packet_capture_" + timestamp + ".pcap"),
        "PCAP Files (*.pcap);;All Files (*)");

    if (!pcapFilePath.isEmpty()) {
        savePacketsToPCAP(pcapFilePath);
    }

    if (!csvFilePath.isEmpty() || !pcapFilePath.isEmpty()) {
        lastExportPath = QFileInfo(csvFilePath.isEmpty() ? pcapFilePath : csvFilePath).absolutePath();
        ui->savingPathLineEdit->setText(lastExportPath);
        updateDiskInformation(lastExportPath);
    }
}

void MainWindow::savePacketsToCSV(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error",
                              QString("Could not open file for writing: %1").arg(file.errorString()));
        return;
    }

    QTextStream out(&file);

    out << "Source MAC,Destination MAC,Source IP,Destination IP,Protocol,Length,Info\n";
    int rowCount = ui->packetTable->rowCount();
    for (int i = 0; i < rowCount; i++) {
        QStringList rowData;
        for (int j = 0; j < 7; j++) {
            QTableWidgetItem* item = ui->packetTable->item(i, j);
            if (item) {
                QString value = item->text();
                if (value.contains(',') || value.contains('"') || value.contains('\n')) {
                    value.replace("\"", "\"\"");
                    value = "\"" + value + "\"";
                }
                rowData << value;
            } else {
                rowData << "";
            }
        }
        out << rowData.join(",") << "\n";
    }

    file.close();
    statusBar()->showMessage(QString("Saved %1 packets to CSV: %2").arg(rowCount).arg(filePath), 5000);
}

void MainWindow::savePacketsToPCAP(const QString &filePath) {
    pcap_t *pd;
    pcap_dumper_t *pdumper;

    pd = pcap_open_dead(DLT_EN10MB, 65535);
    if (pd == nullptr) {
        QMessageBox::critical(this, "Error", "Failed to create PCAP handle");
        return;
    }

    pdumper = pcap_dump_open(pd, filePath.toStdString().c_str());
    if (pdumper == nullptr) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to open PCAP file for writing: %1").arg(pcap_geterr(pd)));
        pcap_close(pd);
        return;
    }

    const QVector<CapturedPacket>& packets = sniffer->getCapturedPackets();
    for (const auto& packet : packets) {
        pcap_dump((u_char*)pdumper, &packet.header, packet.data.data());
    }

    pcap_dump_close(pdumper);
    pcap_close(pd);

    statusBar()->showMessage(QString("Saved %1 packets to PCAP: %2")
                                 .arg(packets.size())
                                 .arg(filePath), 5000);
}

void MainWindow::setupCaptureConstraints(){
    // Connect signals
    connect(ui->packetLimitSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [this](int value) { maxPackets = value; });

    connect(ui->byteLimitSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [this](int value) {
        maxBytes = value*1024*1024;
            });

    maxPackets = ui->packetLimitSpinBox->value();
    maxBytes = (ui->byteLimitSpinBox->value())*1024*1024;
}

void MainWindow::checkCaptureConstraints(int packetSize) {
    capturedPacketsCount++;
    capturedBytesCount += packetSize;

    bool shouldStop = false;
    QString stopReason;

    // Check packet count constraint
    if (maxPackets > 0 && capturedPacketsCount >= maxPackets) {
        shouldStop = true;
        stopReason = QString("Reached packet limit (%1 packets)").arg(maxPackets);
    }

    // Check byte count constraint
    if (maxBytes > 0 && capturedBytesCount >= maxBytes) {
        shouldStop = true;
        stopReason = QString("Reached size limit (%1 bytes)").arg(maxBytes);
    }

    if (shouldStop && sniffer->isRunning()) {
        qDebug() << "Auto-stopping capture:" << stopReason;

        QTimer::singleShot(0, this, [this, stopReason]() {
            if (sniffer->isRunning()) {
                stopCapture();
            }

            // Update UI
            ui->startButton->setChecked(false);
            ui->startButton->setText("Start");
            statusBar()->showMessage("Capture stopped: " + stopReason);
            graphTimer->stop();
            ui->saveButton->setEnabled(true);

            QMessageBox::information(this, "Capture Complete",
                                     "Packet capture stopped: " + stopReason);
        });
        maxPackets = 0;
        maxBytes = 0;
    }
}
