#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QStyleFactory>
#include <QDebug>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    //a.setStyle(QStyleFactory::create("Windows"));
    MainWindow w;
    w.show();

    return a.exec();
}
