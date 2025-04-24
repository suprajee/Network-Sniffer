/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QTableWidget *packetTable;
    QComboBox *protocolFilterComboBox;
    QComboBox *deviceComboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(30, 20, 111, 41));
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
        packetTable->setGeometry(QRect(0, 110, 801, 281));
        protocolFilterComboBox = new QComboBox(centralwidget);
        protocolFilterComboBox->addItem(QString());
        protocolFilterComboBox->addItem(QString());
        protocolFilterComboBox->addItem(QString());
        protocolFilterComboBox->addItem(QString());
        protocolFilterComboBox->addItem(QString());
        protocolFilterComboBox->addItem(QString());
        protocolFilterComboBox->addItem(QString());
        protocolFilterComboBox->setObjectName("protocolFilterComboBox");
        protocolFilterComboBox->setGeometry(QRect(440, 50, 82, 28));
        deviceComboBox = new QComboBox(centralwidget);
        deviceComboBox->setObjectName("deviceComboBox");
        deviceComboBox->setGeometry(QRect(541, 50, 221, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
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
        protocolFilterComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "All", nullptr));
        protocolFilterComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "TCP", nullptr));
        protocolFilterComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "UDP", nullptr));
        protocolFilterComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "TLS", nullptr));
        protocolFilterComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "DNS", nullptr));
        protocolFilterComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "QUIC", nullptr));
        protocolFilterComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Other", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
