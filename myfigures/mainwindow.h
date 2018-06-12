#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camera.h"
#include "toolbar.h"
#include "editpyramiddialog.h"
#include "editspheredialog.h"
#include "editscenedialog.h"
#include "loadscenedialog.h"
#include "database.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void keyPressEvent(QKeyEvent* e);

    QMenu* sceneMenu;
    QMenu* shapeMenu;
    QMenu* editShapeMenu;

    QAction* newSceneAction;
    QAction* editSceneAction;
    QAction* loadSceneAction;
    QAction* saveSceneAction;
    QAction* closeAction;

    QAction* newShapeAction;
    QAction* deleteShapeAction;

    QAction* editPyramidAction;
    QAction* editSphereAction;

    ToolBar*    toolBar;
    QStatusBar* statusBar;

    DataBase* db;

private slots:
    void openAddShapeDialog();
    void openEditPyramidDialog();
    void openEditSphereDialog();
    void openEditSceneDialog();
    void openLoadSceneDialog();
    void createNewScene();
    void saveData();
};

#endif // MAINWINDOW_H
