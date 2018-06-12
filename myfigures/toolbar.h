#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QIcon>
#include "myopenglwidget.h"

class ToolBar : public QToolBar {
    Q_OBJECT

private:

    QAction* xyPlaneAction;
    QAction* yzPlaneAction;
    QAction* zxPlaneAction;
    QAction* xRotationAction;
    QAction* yRotationAction;
    QAction* zRotationAction;
    QAction* xyProjectionAction;
    QAction* yzProjectionAction;
    QAction* zxProjectionAction;
    QAction* xRightAction;
    QAction* xLeftAction;
    QAction* yRightAction;
    QAction* yLeftAction;
    QAction* zRightAction;
    QAction* zLeftAction;

public:
    ToolBar(QWidget*);
    ToolBar(QWidget*, MyOpenGLWidget*);
    ~ToolBar();
};

#endif // TOOLBAR_H
