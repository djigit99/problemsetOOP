#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/gl.h>
#include "quadrangularpyramid.h"
#include "sphere.h"
#include "ellipse.h"
#include "figure.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <QMouseEvent>
#include <camera.h>
#include <QList>

class MyOpenGLWidget : public QOpenGLWidget {
    Q_OBJECT
private:
    float ANGLE_STEP = 2.0;
    float MOVING_STEP = 2.0;
    uint SCENE_ID = 0;
    uint CURRENT_SCENE_ID = 0;

    Camera* camera = new Camera;

    float xCord = 10.f;
    float yCord = 10.f;
    float zCord = 50.f;
    float g_LightPosition[4] = {xCord, yCord, zCord, 1};

public:
    explicit MyOpenGLWidget(QWidget* parent = 0);
    ~MyOpenGLWidget();

    QList<QuadrangularPyramid*> *pyramidList;
    QList<Sphere*> *sphereList;

    bool xyVisible = false;
    bool zxVisible = false;
    bool yzVisible = false;

    bool xyProjectionVisible = false;
    bool yzProjectionVisible = false;
    bool zxProjectionVisible = false;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    int  RetrieveObjectID(int x, int y);
    void RenderScene();
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*);

signals:
    void figureCliked(QString, int);

private slots:
    void rotateX();
    void rotateY();
    void rotateZ();
    void showXY();
    void showZX();
    void showYZ();
    void showXYProjection();
    void showYZProjection();
    void showZXProjection();
    void moveLeft();
    void moveRight();
    void moveDown();
    void moveUp();
    void moveBackward();
    void moveFrontward();
    void deleteShape();

public:
    void drawXY();
    void drawZX();
    void drawYZ();

    void addFigure(Figure*);
    void updateSelected(TYPE, QColor, float par1 = 0, float par2 = 0);
    void updateConfig(float, float);
    void createScene();

    int getCurrId();
    void setCurrId(uint);
    void setSceneId(uint);


};

#endif // MYOPENGLWIDGET_H
