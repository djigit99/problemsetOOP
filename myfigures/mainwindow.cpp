#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addshapedialog.h"
#include <QDebug>
#include <QKeyEvent>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle(tr("ShapeEngine3D"));

    setCentralWidget(ui->openGLWidget);

    sceneMenu = new QMenu(tr("&Scene"));
    shapeMenu = new QMenu(tr("Shape"));
    editShapeMenu = new QMenu(tr("Edit shape"));

    newSceneAction = new QAction(tr("&New scene"));
    editSceneAction = new QAction(tr("&Edit scene"));
    loadSceneAction = new QAction(tr("&Load scene"));
    saveSceneAction = new QAction(tr("&Save scene"));
    closeAction = new QAction(tr("&Close"));

    newShapeAction = new QAction(tr("New shape"));
    deleteShapeAction = new QAction(tr("Delete shape"));
    editPyramidAction = new QAction(tr("Pyramids"));
    editSphereAction = new QAction(tr("Spheres"));

    sceneMenu->addAction(newSceneAction);
    sceneMenu->addAction(editSceneAction);
    sceneMenu->addAction(loadSceneAction);
    sceneMenu->addAction(saveSceneAction);
    sceneMenu->addSeparator();
    sceneMenu->addAction(closeAction);
    shapeMenu->addAction(newShapeAction);
    shapeMenu->addMenu(editShapeMenu);
    shapeMenu->addAction(deleteShapeAction);
    editShapeMenu->addAction(editPyramidAction);
    editShapeMenu->addAction(editSphereAction);

    ui->menuBar->addMenu(sceneMenu);
    ui->menuBar->addMenu(shapeMenu);

    toolBar = new ToolBar(this, ui->openGLWidget);
    addToolBar(toolBar);
    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    db = new DataBase;
    db->connectToDataBase();

    ui->openGLWidget->setSceneId(db->getMaxSceneId()+1);
    ui->openGLWidget->setCurrId(db->getMaxSceneId()+1);

    connect(editSceneAction, SIGNAL(triggered(bool)), this, SLOT(openEditSceneDialog()));
    connect(newShapeAction, SIGNAL(triggered(bool)),this, SLOT(openAddShapeDialog()));
    connect(editPyramidAction, SIGNAL(triggered(bool)), this, SLOT(openEditPyramidDialog()));
    connect(editSphereAction, SIGNAL(triggered(bool)), this, SLOT(openEditSphereDialog()));
    connect(deleteShapeAction, SIGNAL(triggered(bool)), ui->openGLWidget, SLOT(deleteShape()));
    connect(newSceneAction, SIGNAL(triggered(bool)), this, SLOT(createNewScene()));
    connect(saveSceneAction, SIGNAL(triggered(bool)), this, SLOT(saveData()));
    connect(loadSceneAction, SIGNAL(triggered(bool)), this, SLOT(openLoadSceneDialog()));
    connect(ui->openGLWidget, SIGNAL(figureCliked(QString, int)), statusBar, SLOT(showMessage(QString, int)));
    connect(closeAction, SIGNAL(triggered(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow() {
    delete ui;

    delete sceneMenu;
    delete shapeMenu;
    delete editShapeMenu;

    delete newSceneAction;
    delete editSceneAction;
    delete loadSceneAction;
    delete saveSceneAction;
    delete closeAction;

    delete newShapeAction;
    delete deleteShapeAction;

    delete editPyramidAction;
    delete editSphereAction;

    delete toolBar;
    delete statusBar;

    delete db;

}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_Escape:
        close();
        break;
    default:
        break;
    }

}

void MainWindow::openAddShapeDialog() {
    AddShapeDialog* dialog = new AddShapeDialog(this);
    if ( dialog->exec() ) {
        Figure* fig;
        if (dialog->getType() == PYRAMID) {
            QVector3D* vec = dialog->getCords();
            fig = new QuadrangularPyramid(10.f, 10.f, vec->x(), vec->y(), vec->z(),
                                          dialog->getColor());
            delete vec;
        } else {
            QVector3D* vec = dialog->getCords();
            fig = new Sphere(vec->x(), vec->y(), vec->z(), dialog->getColor(), 10.f);
            delete vec;
        }
        ui->openGLWidget->addFigure(fig);
    }
    delete dialog;
}

void MainWindow::openEditPyramidDialog() {
    EditPyramidDialog* dialog = new EditPyramidDialog(this);
    if ( dialog->exec() ) {
        ui->openGLWidget->updateSelected(PYRAMID, dialog->getColor(), dialog->getHeigh(), dialog->getWidth());
    }
    delete dialog;
}

void MainWindow::openEditSphereDialog() {
    EditSphereDialog* dialog = new EditSphereDialog(this);
    if ( dialog->exec() ) {
        ui->openGLWidget->updateSelected(SPHERE, dialog->getColor(), dialog->getRadius());
    }
    delete dialog;
}

void MainWindow::openEditSceneDialog() {
    EditSceneDialog* dialog = new EditSceneDialog(this);
    if (dialog->exec() ) {
        ui->openGLWidget->updateConfig(dialog->getAngleStep(), dialog->getMovingStep());
    }
}

void MainWindow::openLoadSceneDialog() {
    int sceneID = -1;
    LoadSceneDialog* dialog = new LoadSceneDialog(this);
    if (dialog->exec() ) {
        sceneID = dialog->getId();
    }
    if (sceneID == -1) {
        return;
    }

    ui->openGLWidget->setCurrId(sceneID);
    ui->openGLWidget->pyramidList->clear();
    ui->openGLWidget->sphereList->clear();

    QVariantList list = db->getData(sceneID);
    for (int i = 0; i < list.size(); i+=12) {
        QString typeStr = list[i].toString();
        int colorR      = list[(i+1)].toInt();
        int colorG      = list[(i+2)].toInt();
        int colorB      = list[(i+3)].toInt();
        float angleX    = list[(i+4)].toFloat();
        float angleY    = list[(i+5)].toFloat();
        float angleZ    = list[(i+6)].toFloat();
        float cordX     = list[(i+7)].toFloat();
        float cordY     = list[(i+8)].toFloat();
        float cordZ     = list[(i+9)].toFloat();
        float width     = list[(i+10)].toFloat();
        float height    = list[(i+11)].toFloat();
        qDebug() << typeStr;
        if (typeStr.toStdString() == "SPHERE") {
            Sphere* nSphere = new Sphere(cordX, cordY, cordZ, QColor(colorR, colorG, colorB), width);
            nSphere->setXAngle(angleX);
            nSphere->setYAngle(angleY);
            nSphere->setZAngle(angleZ);
            ui->openGLWidget->sphereList->append(nSphere);
        } else {
            QuadrangularPyramid* nPyramid = new QuadrangularPyramid(width, height, cordX, cordY, cordZ,
                                                                    QColor(colorR, colorG, colorB));
            nPyramid->setXAngle(angleX);
            nPyramid->setYAngle(angleY);
            nPyramid->setZAngle(angleZ);
            ui->openGLWidget->pyramidList->append(nPyramid);
        }
    }
    ui->openGLWidget->update();
}

void MainWindow::createNewScene() {
    ui->openGLWidget->createScene();
}

void MainWindow::saveData() {
    db->clearData(ui->openGLWidget->getCurrId());

    QList<QuadrangularPyramid*>* list = ui->openGLWidget->pyramidList;
    for (int i = 0; i < list->size(); i++) {
        QVariantList vList;
        vList.append(ui->openGLWidget->getCurrId());
        vList.append("PYRAMID");
        vList.append(list->at(i)->getColor().red());
        vList.append(list->at(i)->getColor().green());
        vList.append(list->at(i)->getColor().blue());
        vList.append(list->at(i)->getXAngle());
        vList.append(list->at(i)->getYAngle());
        vList.append(list->at(i)->getZAngle());
        vList.append(list->at(i)->getXCord());
        vList.append(list->at(i)->getYCord());
        vList.append(list->at(i)->getZCord());
        vList.append(list->at(i)->getWidth());
        vList.append(list->at(i)->getHeight());
        db->insertIntoDeviceTable(vList);
    }

    QList<Sphere*> *list2 = ui->openGLWidget->sphereList;
    for (int i = 0; i < list2->size(); i++) {
        QVariantList vList;
        vList.append(ui->openGLWidget->getCurrId());
        vList.append("SPHERE");
        vList.append(list2->at(i)->getColor().red());
        vList.append(list2->at(i)->getColor().green());
        vList.append(list2->at(i)->getColor().blue());
        vList.append(list2->at(i)->getXAngle());
        vList.append(list2->at(i)->getYAngle());
        vList.append(list2->at(i)->getZAngle());
        vList.append(list2->at(i)->getXCord());
        vList.append(list2->at(i)->getYCord());
        vList.append(list2->at(i)->getZCord());
        vList.append(list2->at(i)->getRadius());
        vList.append(list2->at(i)->getRadius());
        db->insertIntoDeviceTable(vList);
    }
}

