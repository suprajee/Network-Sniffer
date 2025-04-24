/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_main;
    QHBoxLayout *topControlsLayout;
    QPushButton *startButton;
    QComboBox *deviceComboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QTableWidget *packetTable;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QHBoxLayout *horizontalLayout_tab1;
    QGroupBox *groupBox_19;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QLabel *label_29;
    QLabel *label_45;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *diskCapacityLineEdit;
    QLineEdit *diskSpaceLineEdit;
    QLineEdit *diskUsageLineEdit;
    QHBoxLayout *horizontalLayout_30;
    QLineEdit *savingPathLineEdit;
    QPushButton *browseButton;
    QGroupBox *groupBox_20;
    QVBoxLayout *verticalLayout_37;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_31;
    QSpinBox *packetLimitSpinBox;
    QLabel *label_32;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_30;
    QSpinBox *byteLimitSpinBox;
    QLabel *label_33;
    QGroupBox *groupBox_29;
    QHBoxLayout *horizontalLayout_39;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_38;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_23;
    QVBoxLayout *verticalLayout_39;
    QLineEdit *l1;
    QLineEdit *l2;
    QLineEdit *macaddress;
    QWidget *tab2;
    QHBoxLayout *horizontalLayout_tab2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QListWidget *ipListWidget;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *ipOctet1;
    QLineEdit *ipOctet2;
    QLineEdit *ipOctet3;
    QLineEdit *ipOctet4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addIpButton;
    QPushButton *removeIpButton;
    QCheckBox *eitherCheckBox;
    QCheckBox *destinationCheckBox;
    QCheckBox *sourceCheckBox;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_42;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *tcpCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_22;
    QCheckBox *dnsCheckBox;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *udpCheckBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_20;
    QFrame *line;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_28;
    QCheckBox *tlsCheckBox;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_35;
    QCheckBox *quicCheckBox;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_34;
    QHBoxLayout *horizontalLayout_36;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_29;
    QCheckBox *allCheckBox;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_14;
    QWidget *tab3;
    QHBoxLayout *horizontalLayout_tab3;
    QChartView *trafficChartView;
    QVBoxLayout *verticalLayout;
    QWidget *tab4;
    QHBoxLayout *horizontalLayout_tab4;
    QHBoxLayout *hexDumpLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1311, 755);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_main = new QVBoxLayout(centralwidget);
        verticalLayout_main->setObjectName("verticalLayout_main");
        topControlsLayout = new QHBoxLayout();
        topControlsLayout->setObjectName("topControlsLayout");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setMinimumSize(QSize(120, 40));
        startButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #218838;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #218838;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1e7e34;\n"
"}\n"
""));

        topControlsLayout->addWidget(startButton);

        deviceComboBox = new QComboBox(centralwidget);
        deviceComboBox->setObjectName("deviceComboBox");
        deviceComboBox->setMinimumSize(QSize(250, 40));

        topControlsLayout->addWidget(deviceComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topControlsLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setMinimumSize(QSize(100, 40));

        topControlsLayout->addWidget(saveButton);


        verticalLayout_main->addLayout(topControlsLayout);

        packetTable = new QTableWidget(centralwidget);
        if (packetTable->columnCount() < 7)
            packetTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        packetTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        packetTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        packetTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        packetTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        packetTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        packetTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        packetTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        packetTable->setObjectName("packetTable");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(packetTable->sizePolicy().hasHeightForWidth());
        packetTable->setSizePolicy(sizePolicy);
        packetTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_main->addWidget(packetTable);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 300));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tab1 = new QWidget();
        tab1->setObjectName("tab1");
        horizontalLayout_tab1 = new QHBoxLayout(tab1);
        horizontalLayout_tab1->setObjectName("horizontalLayout_tab1");
        groupBox_19 = new QGroupBox(tab1);
        groupBox_19->setObjectName("groupBox_19");
        groupBox_19->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_19->sizePolicy().hasHeightForWidth());
        groupBox_19->setSizePolicy(sizePolicy2);
        horizontalLayout_2 = new QHBoxLayout(groupBox_19);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_15 = new QLabel(groupBox_19);
        label_15->setObjectName("label_15");

        verticalLayout_4->addWidget(label_15);

        label_29 = new QLabel(groupBox_19);
        label_29->setObjectName("label_29");

        verticalLayout_4->addWidget(label_29);

        label_45 = new QLabel(groupBox_19);
        label_45->setObjectName("label_45");

        verticalLayout_4->addWidget(label_45);

        label_18 = new QLabel(groupBox_19);
        label_18->setObjectName("label_18");

        verticalLayout_4->addWidget(label_18);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        diskCapacityLineEdit = new QLineEdit(groupBox_19);
        diskCapacityLineEdit->setObjectName("diskCapacityLineEdit");
        diskCapacityLineEdit->setEnabled(false);

        verticalLayout_2->addWidget(diskCapacityLineEdit);

        diskSpaceLineEdit = new QLineEdit(groupBox_19);
        diskSpaceLineEdit->setObjectName("diskSpaceLineEdit");
        diskSpaceLineEdit->setEnabled(false);

        verticalLayout_2->addWidget(diskSpaceLineEdit);

        diskUsageLineEdit = new QLineEdit(groupBox_19);
        diskUsageLineEdit->setObjectName("diskUsageLineEdit");
        diskUsageLineEdit->setEnabled(false);

        verticalLayout_2->addWidget(diskUsageLineEdit);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        savingPathLineEdit = new QLineEdit(groupBox_19);
        savingPathLineEdit->setObjectName("savingPathLineEdit");
        savingPathLineEdit->setEnabled(false);
        savingPathLineEdit->setReadOnly(true);

        horizontalLayout_30->addWidget(savingPathLineEdit);

        browseButton = new QPushButton(groupBox_19);
        browseButton->setObjectName("browseButton");
        browseButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_30->addWidget(browseButton);


        verticalLayout_2->addLayout(horizontalLayout_30);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_tab1->addWidget(groupBox_19);

        groupBox_20 = new QGroupBox(tab1);
        groupBox_20->setObjectName("groupBox_20");
        sizePolicy2.setHeightForWidth(groupBox_20->sizePolicy().hasHeightForWidth());
        groupBox_20->setSizePolicy(sizePolicy2);
        verticalLayout_37 = new QVBoxLayout(groupBox_20);
        verticalLayout_37->setObjectName("verticalLayout_37");
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        label_31 = new QLabel(groupBox_20);
        label_31->setObjectName("label_31");

        horizontalLayout_32->addWidget(label_31);

        packetLimitSpinBox = new QSpinBox(groupBox_20);
        packetLimitSpinBox->setObjectName("packetLimitSpinBox");
        packetLimitSpinBox->setStyleSheet(QString::fromUtf8(""));
        packetLimitSpinBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        packetLimitSpinBox->setMaximum(1000000);
        packetLimitSpinBox->setValue(1000);

        horizontalLayout_32->addWidget(packetLimitSpinBox);

        label_32 = new QLabel(groupBox_20);
        label_32->setObjectName("label_32");

        horizontalLayout_32->addWidget(label_32);


        verticalLayout_37->addLayout(horizontalLayout_32);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName("horizontalLayout_41");
        label_30 = new QLabel(groupBox_20);
        label_30->setObjectName("label_30");

        horizontalLayout_41->addWidget(label_30);

        byteLimitSpinBox = new QSpinBox(groupBox_20);
        byteLimitSpinBox->setObjectName("byteLimitSpinBox");
        byteLimitSpinBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        byteLimitSpinBox->setMaximum(1024);
        byteLimitSpinBox->setValue(1024);

        horizontalLayout_41->addWidget(byteLimitSpinBox);

        label_33 = new QLabel(groupBox_20);
        label_33->setObjectName("label_33");

        horizontalLayout_41->addWidget(label_33);


        verticalLayout_37->addLayout(horizontalLayout_41);


        horizontalLayout_tab1->addWidget(groupBox_20);

        groupBox_29 = new QGroupBox(tab1);
        groupBox_29->setObjectName("groupBox_29");
        sizePolicy2.setHeightForWidth(groupBox_29->sizePolicy().hasHeightForWidth());
        groupBox_29->setSizePolicy(sizePolicy2);
        horizontalLayout_39 = new QHBoxLayout(groupBox_29);
        horizontalLayout_39->setObjectName("horizontalLayout_39");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setObjectName("verticalLayout_38");
        label_24 = new QLabel(groupBox_29);
        label_24->setObjectName("label_24");

        verticalLayout_38->addWidget(label_24);

        label_22 = new QLabel(groupBox_29);
        label_22->setObjectName("label_22");

        verticalLayout_38->addWidget(label_22);

        label_23 = new QLabel(groupBox_29);
        label_23->setObjectName("label_23");

        verticalLayout_38->addWidget(label_23);


        horizontalLayout_3->addLayout(verticalLayout_38);

        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setObjectName("verticalLayout_39");
        l1 = new QLineEdit(groupBox_29);
        l1->setObjectName("l1");
        l1->setEnabled(false);
        l1->setReadOnly(true);

        verticalLayout_39->addWidget(l1);

        l2 = new QLineEdit(groupBox_29);
        l2->setObjectName("l2");
        l2->setEnabled(false);
        l2->setReadOnly(true);

        verticalLayout_39->addWidget(l2);

        macaddress = new QLineEdit(groupBox_29);
        macaddress->setObjectName("macaddress");
        macaddress->setEnabled(false);
        macaddress->setReadOnly(true);

        verticalLayout_39->addWidget(macaddress);


        horizontalLayout_3->addLayout(verticalLayout_39);


        horizontalLayout_39->addLayout(horizontalLayout_3);


        horizontalLayout_tab1->addWidget(groupBox_29);

        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName("tab2");
        horizontalLayout_tab2 = new QHBoxLayout(tab2);
        horizontalLayout_tab2->setObjectName("horizontalLayout_tab2");
        groupBox_7 = new QGroupBox(tab2);
        groupBox_7->setObjectName("groupBox_7");
        sizePolicy2.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy2);
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setObjectName("gridLayout_7");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        ipListWidget = new QListWidget(groupBox_7);
        ipListWidget->setObjectName("ipListWidget");

        verticalLayout_9->addWidget(ipListWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        ipOctet1 = new QLineEdit(groupBox_7);
        ipOctet1->setObjectName("ipOctet1");
        ipOctet1->setMaxLength(3);

        horizontalLayout_5->addWidget(ipOctet1);

        ipOctet2 = new QLineEdit(groupBox_7);
        ipOctet2->setObjectName("ipOctet2");
        ipOctet2->setMaxLength(3);

        horizontalLayout_5->addWidget(ipOctet2);

        ipOctet3 = new QLineEdit(groupBox_7);
        ipOctet3->setObjectName("ipOctet3");
        ipOctet3->setMaxLength(3);

        horizontalLayout_5->addWidget(ipOctet3);

        ipOctet4 = new QLineEdit(groupBox_7);
        ipOctet4->setObjectName("ipOctet4");
        ipOctet4->setMaxLength(3);

        horizontalLayout_5->addWidget(ipOctet4);


        verticalLayout_9->addLayout(horizontalLayout_5);


        verticalLayout_8->addLayout(verticalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        addIpButton = new QPushButton(groupBox_7);
        addIpButton->setObjectName("addIpButton");

        horizontalLayout_7->addWidget(addIpButton);

        removeIpButton = new QPushButton(groupBox_7);
        removeIpButton->setObjectName("removeIpButton");

        horizontalLayout_7->addWidget(removeIpButton);


        verticalLayout_8->addLayout(horizontalLayout_7);


        gridLayout_7->addLayout(verticalLayout_8, 3, 0, 1, 1);

        eitherCheckBox = new QCheckBox(groupBox_7);
        eitherCheckBox->setObjectName("eitherCheckBox");

        gridLayout_7->addWidget(eitherCheckBox, 2, 0, 1, 1);

        destinationCheckBox = new QCheckBox(groupBox_7);
        destinationCheckBox->setObjectName("destinationCheckBox");

        gridLayout_7->addWidget(destinationCheckBox, 1, 0, 1, 1);

        sourceCheckBox = new QCheckBox(groupBox_7);
        sourceCheckBox->setObjectName("sourceCheckBox");

        gridLayout_7->addWidget(sourceCheckBox, 0, 0, 1, 1);


        horizontalLayout_tab2->addWidget(groupBox_7);

        groupBox_14 = new QGroupBox(tab2);
        groupBox_14->setObjectName("groupBox_14");
        sizePolicy2.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy2);
        verticalLayout_7 = new QVBoxLayout(groupBox_14);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_9 = new QLabel(groupBox_14);
        label_9->setObjectName("label_9");

        verticalLayout_7->addWidget(label_9);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName("horizontalLayout_42");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        tcpCheckBox = new QCheckBox(groupBox_14);
        tcpCheckBox->setObjectName("tcpCheckBox");

        horizontalLayout_4->addWidget(tcpCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        horizontalLayout_18->addLayout(horizontalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_6);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        dnsCheckBox = new QCheckBox(groupBox_14);
        dnsCheckBox->setObjectName("dnsCheckBox");

        horizontalLayout_22->addWidget(dnsCheckBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout_22);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_4);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        udpCheckBox = new QCheckBox(groupBox_14);
        udpCheckBox->setObjectName("udpCheckBox");

        horizontalLayout_19->addWidget(udpCheckBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");

        verticalLayout_5->addLayout(horizontalLayout_20);


        horizontalLayout_42->addLayout(verticalLayout_5);

        line = new QFrame(groupBox_14);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_42->addWidget(line);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        tlsCheckBox = new QCheckBox(groupBox_14);
        tlsCheckBox->setObjectName("tlsCheckBox");

        horizontalLayout_28->addWidget(tlsCheckBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_28);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_11);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName("horizontalLayout_35");
        quicCheckBox = new QCheckBox(groupBox_14);
        quicCheckBox->setObjectName("quicCheckBox");

        horizontalLayout_35->addWidget(quicCheckBox);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_10);


        verticalLayout_6->addLayout(horizontalLayout_35);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName("horizontalLayout_34");

        verticalLayout_6->addLayout(horizontalLayout_34);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName("horizontalLayout_36");
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_12);


        verticalLayout_6->addLayout(horizontalLayout_36);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        allCheckBox = new QCheckBox(groupBox_14);
        allCheckBox->setObjectName("allCheckBox");
        allCheckBox->setChecked(true);

        horizontalLayout_29->addWidget(allCheckBox);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_9);


        verticalLayout_6->addLayout(horizontalLayout_29);


        horizontalLayout_42->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_42);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_13);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_14);


        horizontalLayout_tab2->addWidget(groupBox_14);

        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName("tab3");
        horizontalLayout_tab3 = new QHBoxLayout(tab3);
        horizontalLayout_tab3->setObjectName("horizontalLayout_tab3");
        trafficChartView = new QChartView(tab3);
        trafficChartView->setObjectName("trafficChartView");

        horizontalLayout_tab3->addWidget(trafficChartView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        horizontalLayout_tab3->addLayout(verticalLayout);

        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName("tab4");
        tab4->setEnabled(true);
        tab4->setMinimumSize(QSize(1285, 0));
        tab4->setMaximumSize(QSize(1285, 16777215));
        tab4->setAcceptDrops(false);
        tab4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayout_tab4 = new QHBoxLayout(tab4);
        horizontalLayout_tab4->setObjectName("horizontalLayout_tab4");
        hexDumpLayout = new QHBoxLayout();
        hexDumpLayout->setObjectName("hexDumpLayout");

        horizontalLayout_tab4->addLayout(hexDumpLayout);

        tabWidget->addTab(tab4, QString());

        verticalLayout_main->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1311, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        QTableWidgetItem *___qtablewidgetitem = packetTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Src MAC", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = packetTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Dest MAC", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = packetTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Src IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = packetTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Dest IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = packetTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Protocol", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = packetTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = packetTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
        groupBox_19->setTitle(QCoreApplication::translate("MainWindow", "Disk ", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Disk Capacity", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Disk Space", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "Disk Usage", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Saving Path", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("MainWindow", "End capture session", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "After :", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Packets", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "After :", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "MegaByte", nullptr));
        groupBox_29->setTitle(QCoreApplication::translate("MainWindow", "Network basic informations", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Adapter name:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "MAC Address: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QCoreApplication::translate("MainWindow", "Home", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Fixed IP Address", nullptr));
        addIpButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeIpButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        eitherCheckBox->setText(QCoreApplication::translate("MainWindow", "source or destination", nullptr));
        destinationCheckBox->setText(QCoreApplication::translate("MainWindow", "destination", nullptr));
        sourceCheckBox->setText(QCoreApplication::translate("MainWindow", "source", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "Protocol Filter", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        tcpCheckBox->setText(QCoreApplication::translate("MainWindow", "TCP", nullptr));
        dnsCheckBox->setText(QCoreApplication::translate("MainWindow", "DNS", nullptr));
        udpCheckBox->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        tlsCheckBox->setText(QCoreApplication::translate("MainWindow", "TLS", nullptr));
        quicCheckBox->setText(QCoreApplication::translate("MainWindow", "QUIC", nullptr));
        allCheckBox->setText(QCoreApplication::translate("MainWindow", "ALL", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QCoreApplication::translate("MainWindow", "Filters", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("MainWindow", "Analysis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QCoreApplication::translate("MainWindow", "HexValue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
