#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timeritem.h"

#include <QListWidget>
#include <QHBoxLayout>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {

    setWindowTitle(QString("TimerWow"));

    QListWidget* listWidget = new QListWidget(this);
    QListWidgetItem* listWidgetItem  = new QListWidgetItem();
    TimerItem* timerItem = new TimerItem(this);

    listWidgetItem->setSizeHint(timerItem->sizeHint());
    setFixedWidth(timerItem->sizeHint().width() + 15);
    listWidget->addItem(listWidgetItem);
    listWidget->setItemWidget(listWidgetItem, timerItem);

    setCentralWidget(listWidget);

}

MainWindow::~MainWindow() {

}

