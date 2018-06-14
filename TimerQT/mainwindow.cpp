#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timeritem.h"

#include <QListWidget>
#include <QHBoxLayout>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    setWindowTitle(QString("TimerWow"));
    // QListWidget;
    // QListWidgetItem
    // QWidget
    // QLabel QPushButton
    // QHBoxLayout
    // QHBoxLayout add QLabel , add QPushButton
    // QWidget setLayout QHBoxLayout
    // QListWidget add QListWidgetItem
    // QListWidget setItemWidget(QListWidgetItem, QWidget)

    QListWidget* listWidget = new QListWidget(this);
    QListWidgetItem* listWidgetItem = new QListWidgetItem();
    TimerItem* timerItem = new TimerItem(this);

    listWidgetItem->setSizeHint(timerItem->sizeHint());
    listWidget->addItem(listWidgetItem);
    listWidget->setItemWidget(listWidgetItem, timerItem);

    setCentralWidget(listWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

