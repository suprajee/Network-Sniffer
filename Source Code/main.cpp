#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    } catch (const std::exception &e) {
        qDebug() << "Exception caught:" << e.what();
        QMessageBox::critical(nullptr, "Critical Error", QString("An error occurred: %1").arg(e.what()));
        return -1;
    } catch (...) {
        qDebug() << "Unknown error occurred!";
        QMessageBox::critical(nullptr, "Critical Error", "An unknown error occurred!");
        return -1;
    }
}
