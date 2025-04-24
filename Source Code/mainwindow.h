#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QSettings>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QFileDialog>
#include <QStorageInfo>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include <QTextEdit>
#include <QListWidgetItem>
#include "packetsniffer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

QT_USE_NAMESPACE
    struct IPFilterEntry {
    QString ip;
    enum MatchType { Source, Destination, Either } matchType;
};
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startCapture();
    void stopCapture();
    void toggleCapture();
    void updatePacketTable(QString srcMac, QString destMac, QString srcIP, QString destIP, QString protocol, int length, QString info);
    void onProtocolFilterChanged();
    void onCaptureStarted(QString deviceName);
    void onCaptureError(QString errorMessage);


private:
    Ui::MainWindow *ui;
    PacketSniffer *sniffer;
    QString currentProtocolFilter = "All";
    QVector<NetworkInterface> deviceData;
    void populateDeviceList();
    void updateNetworkInfo(const NetworkInterface &Interface);
    void onDeviceSelected(int index);
    QStringList getSelectedProtocols();
    QList<IPFilterEntry> ipFilterList;
    // New Chart related variables
    void setupGraph();
    void updateGraph();
    QTimer *graphUpdateTimer;
    QChart *chart;
    QBarSeries *series;
    QChartView *chartView;
    QMap<QString, int> protocolCounts;
    int totalPackets = 0;
    QChart *trafficChart;
    QLineSeries *packetSeries;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QTimer *graphTimer;
    int timeCounter = 0;
    int packetsThisSecond = 0;
    void setupTrafficChart();
    QString lastExportPath;
    int maxPackets = 0;         // Maximum packets to capture (0 = unlimited)
    int maxBytes = 0;           // Maximum bytes to capture (0 = unlimited)
    int capturedPacketsCount = 0;
    qint64 capturedBytesCount = 0;
    QTextEdit *hexDumpView;
    QTimer *updateTimer;
    int selectedRow;
    QString createHexDump(const u_char *packet, int length);
    QString formatHexByte(u_char byte);
    QString formatAsciiChar(u_char byte);
    void updateHexDumpView(const u_char *packet, int length);
    void updateDelayedHexDump();
    // Functions for capture constraints
    void setupCaptureConstraints();
    void checkCaptureConstraints(int packetSize);
    void savePacketsToCSV(const QString &filePath);
    void savePacketsToPCAP(const QString &filePath);
private slots:
    void updateTrafficGraph();
    void showAlert(const QString &message);
    void onBrowseButtonClicked();
    void updateDiskInformation(const QString &path);
    void onSaveButtonClicked();
    void updateSaveButtonState();
    void onAddIpFilterClicked();
    void onRemoveIpFilterClicked();
    void onFixedIpFilterChanged();
    void onPacketSelected();
};

#endif
