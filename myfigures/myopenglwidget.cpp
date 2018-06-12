#include "myopenglwidget.h"
#include <iostream>

MyOpenGLWidget::MyOpenGLWidget(QWidget* parent) :
        QOpenGLWidget(parent) {

    pyramidList = new QList<QuadrangularPyramid*>;
    sphereList = new QList<Sphere*>;
}
MyOpenGLWidget::~MyOpenGLWidget() {
    pyramidList->clear();
    delete pyramidList;
    sphereList->clear();
    delete sphereList;
}

void MyOpenGLWidget::initializeGL() {
    glClearColor(0.0f, 0.0f, 0.1f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
}
void MyOpenGLWidget::resizeGL(int w, int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 500.0);
    glMatrixMode(GL_MODELVIEW);
}
void MyOpenGLWidget::paintGL() {
    /*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glm::vec3 pos = camera->getPosition();
    glm::vec3 view = camera->getViewDirection();
    glm::vec3 up = camera->getUP();

    g_LightPosition[0] = 50.f;
    g_LightPosition[1] = 50.f;
    g_LightPosition[2] = 50.f;
    g_LightPosition[3] = 1;
    glLightfv( GL_LIGHT0, GL_POSITION, g_LightPosition);

    gluLookAt(pos.x, pos.y, pos.z, pos.x + view.x, pos.y + view.y, pos.z + view.z,
                up.x, up.y, up.z);

    drawXY();
    drawYZ();
    drawZX();

    Ellipse* ellipse = new Ellipse(0.f, 0.f, 0.f, 10.f, 20.f, QColor("red"));
    ellipse->draw();
    */

    RenderScene();
}


void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *e) {

}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *e) {
    if (e->buttons() & Qt::LeftButton) {
        uint objectID;

        objectID = RetrieveObjectID(e->x(), e->y());

        for (int i = 0; i < pyramidList->size(); i++) {
            if (pyramidList->at(i)->getId() == objectID) {
                if ( pyramidList->at(i)->reSelected() ) {
                    emit figureCliked("Pyramid's selected", 2000);
                } else {
                    emit figureCliked("Pyramid's unselected", 2000);
                }
                update();
            }
        }
        for (int i = 0; i < sphereList->size(); i++) {
            if (sphereList->at(i)->getId() == objectID) {
                if ( sphereList->at(i)->reSelected() ) {
                    emit figureCliked("Sphere's selected", 2000);
                } else {
                    emit figureCliked("Sphere's unselected", 2000);
                }
                update();
            }
        }
    }
    setFocus();
}
void MyOpenGLWidget::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
    case Qt::Key_W: {
        camera->moveForward();
        update();
        break;
    }
    case Qt::Key_S: {
        camera->moveBackward();
        update();
        break;
    }
    case Qt::Key_A: {
        camera->strafeLeft();
        update();
        break;
    }
    case Qt::Key_D: {
        camera->strafeRight();
        update();
        break;
    }
    case Qt::Key_Q: {
        camera->moveUp();
        update();
        break;
    }
    case Qt::Key_E: {
        camera->moveDown();
        update();
        break;
    }
    default:
        break;
    }
}

void MyOpenGLWidget::addFigure(Figure *figure) {
    switch (figure->getType()) {
    case PYRAMID:
        pyramidList->append(dynamic_cast<QuadrangularPyramid*>(figure));
        update();
        break;
    case SPHERE:
        sphereList->append(dynamic_cast<Sphere*>(figure));
        update();
        break;
    default:
        break;
    }
}

void MyOpenGLWidget::updateSelected(TYPE type, QColor color,
                                        float par1, float par2 ) {
    switch(type) {
    case SPHERE: {
        for (int i = 0; i < sphereList->size(); i++) {
            if (sphereList->at(i)->isSelected()) {
                if (color.isValid() ) {
                    sphereList->at(i)->setColor(color);
                }
                if (par1 > 0.f) {
                    sphereList->at(i)->setRadius(par1);
                }
            }
        }
        update();
    }
        break;
    case PYRAMID: {
        for (int i = 0; i < pyramidList->size(); i++) {
            if (pyramidList->at(i)->isSelected()) {
                if (color.isValid() ) {
                    pyramidList->at(i)->setColor(color);
                }
                if (par1 > 0.f) {
                    pyramidList->at(i)->setHeight(par1);
                    pyramidList->at(i)->updateSizeArray();
                }
                if (par2 > 0.f) {
                    pyramidList->at(i)->setWidth(par2);
                    pyramidList->at(i)->updateSizeArray();
                }
            }
        }
        update();
    }
        break;
    default:
        break;
    }
}


void MyOpenGLWidget::rotateX() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incAngleX(ANGLE_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incAngleX(ANGLE_STEP);
    }
    update();
}

void MyOpenGLWidget::rotateY() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incAngleY(ANGLE_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incAngleY(ANGLE_STEP);
    }
    update();
}

void MyOpenGLWidget::rotateZ() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incAngleZ(ANGLE_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incAngleZ(ANGLE_STEP);
    }
    update();
}

void MyOpenGLWidget::drawXY() {
    if (!xyVisible)
        return ;
    glColor3f(1.f, 0.f, 0.f);
    glBegin(GL_LINES);
    for (int i = -15; i <= 15; i++) {
        glVertex3f((float)i * 5, -75.f, 0.f);
        glVertex3f((float)i * 5, 75.f, 0.f);
        glVertex3f(-75.f, (float)i * 5, 0.f);
        glVertex3f(75.f, (float)i * 5, 0.f);
    }
    glEnd();
}

void MyOpenGLWidget::drawZX() {
    if (!zxVisible)
        return ;
    glColor3f(0.f, 1.f, 0.f);
    glBegin(GL_LINES);
    for (int i = -15; i <= 15; i++) {
        glVertex3f((float)i * 5, 0.f, -75.f);
        glVertex3f((float)i * 5, 0.f, 75.f);
        glVertex3f(-75.f, 0.f, (float)i * 5);
        glVertex3f(75.f, 0.f, (float)i * 5);
    }
    glEnd();
}

void MyOpenGLWidget::drawYZ() {
    if (!yzVisible)
        return ;
    glColor3f(0.f, 0.f, 1.f);
    glBegin(GL_LINES);
    for (int i = -15; i <= 15; i++) {
        glVertex3f(0.f, (float)i * 5, -75.f);
        glVertex3f(0.f, (float)i * 5, 75.f);
        glVertex3f(0.f, -75.f, (float)i * 5);
        glVertex3f(0.f, 75.f, (float)i * 5);
    }
    glEnd();
}


void MyOpenGLWidget::showXY() {
    xyVisible = (xyVisible == false);
    update();
}

void MyOpenGLWidget::showZX() {
    zxVisible = (zxVisible == false);
    update();
}

void MyOpenGLWidget::showYZ() {
    yzVisible = (yzVisible == false);
    update();
}

void MyOpenGLWidget::showXYProjection() {
    xyProjectionVisible = (xyProjectionVisible == false);
    update();
}

void MyOpenGLWidget::showYZProjection() {
    yzProjectionVisible = (yzProjectionVisible == false);
    update();
}

void MyOpenGLWidget::showZXProjection() {
    zxProjectionVisible = (zxProjectionVisible == false);
    update();
}

void MyOpenGLWidget::moveLeft() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incXCord(-MOVING_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incXCord(-MOVING_STEP);
    }
    update();
}

void MyOpenGLWidget::moveRight() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incXCord(MOVING_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incXCord(MOVING_STEP);
    }
    update();
}

void MyOpenGLWidget::moveDown() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incYCord(-MOVING_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incYCord(-MOVING_STEP);
    }
    update();
}

void MyOpenGLWidget::moveUp() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incYCord(MOVING_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incYCord(MOVING_STEP);
    }
    update();
}

void MyOpenGLWidget::moveBackward() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incZCord(-MOVING_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incZCord(-MOVING_STEP);
    }
    update();
}

void MyOpenGLWidget::moveFrontward() {
    for (int i = 0; i < sphereList->size(); i++) {
        if ( !sphereList->at(i)->isSelected())
            continue;
        sphereList->at(i)->incZCord(MOVING_STEP);
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        if ( !pyramidList->at(i)->isSelected())
            continue;
        pyramidList->at(i)->incZCord(MOVING_STEP);
    }
    update();
}

void MyOpenGLWidget::deleteShape() {
    QList<QuadrangularPyramid*>::iterator pyramidItetator = pyramidList->begin();
    while (pyramidItetator != pyramidList->end() ) {
        if ((*pyramidItetator)->isSelected()) {
            pyramidItetator = pyramidList->erase(pyramidItetator);
        } else {
            ++pyramidItetator;
        }
    }
    QList<Sphere*>::iterator sphereItetator = sphereList->begin();
    while (sphereItetator != sphereList->end() ) {
        if ((*sphereItetator)->isSelected()) {
            sphereItetator = sphereList->erase(sphereItetator);
        } else {
            ++sphereItetator;
        }
    }
}

void MyOpenGLWidget::updateConfig(float angleStep, float movingStep) {
    ANGLE_STEP = angleStep;
    MOVING_STEP = movingStep;
}

void MyOpenGLWidget::createScene() {
    CURRENT_SCENE_ID = SCENE_ID;
    SCENE_ID++;
    pyramidList->clear();
    sphereList->clear();
    update();
}

void MyOpenGLWidget::setCurrId(uint id) {
    CURRENT_SCENE_ID = id;
}

void MyOpenGLWidget::setSceneId(uint id) {
    SCENE_ID = id;
}

int MyOpenGLWidget::getCurrId() {
    return CURRENT_SCENE_ID;
}

void MyOpenGLWidget::RenderScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glm::vec3 pos = camera->getPosition();
    glm::vec3 view = camera->getViewDirection();
    glm::vec3 up = camera->getUP();

    g_LightPosition[0] = 50.f;
    g_LightPosition[1] = 50.f;
    g_LightPosition[2] = 50.f;
    g_LightPosition[3] = 1;
    glLightfv( GL_LIGHT0, GL_POSITION, g_LightPosition);

    gluLookAt(pos.x, pos.y, pos.z, pos.x + view.x, pos.y + view.y, pos.z + view.z,
                up.x, up.y, up.z);

    drawXY();
    drawYZ();
    drawZX();

    glInitNames();
    for (int i = 0; i < sphereList->size(); i++) {
        sphereList->at(i)->draw();
        if (sphereList->at(i)->isSelected()) {
            if (xyProjectionVisible) {
                sphereList->at(i)->drawProjectionXY();
            }
            if (yzProjectionVisible) {
                sphereList->at(i)->drawProjectionYZ();
            }
            if (zxProjectionVisible) {
                sphereList->at(i)->drawProjectionZX();
            }
        }
    }
    for (int i = 0; i < pyramidList->size(); i++) {
        pyramidList->at(i)->draw();
        if (pyramidList->at(i)->isSelected()) {
            if (xyProjectionVisible) {
                pyramidList->at(i)->drawProjectionXY();
            }
            if (yzProjectionVisible) {
                pyramidList->at(i)->drawProjectionYZ();
            }
            if (zxProjectionVisible) {
                pyramidList->at(i)->drawProjectionZX();
            }
        }
    }
}

int MyOpenGLWidget::RetrieveObjectID(int x, int y) {
    int objectsFound = 0;
    int viewportCoords[4] = {0};

    unsigned int selectBuffer[32] = {0};


    glSelectBuffer(32, selectBuffer);

    glGetIntegerv(GL_VIEWPORT, viewportCoords);


    glMatrixMode(GL_PROJECTION);

    glPushMatrix();

        glRenderMode(GL_SELECT);

        glLoadIdentity();

        viewportCoords[3] = this->size().height();
        viewportCoords[2] = this->size().width();
        gluPickMatrix(x, viewportCoords[3] - y, 1, 1, viewportCoords);

        gluPerspective(45, (float)this->size().width() / (float)this->size().height(), 0.01, 500.0);

        glMatrixMode(GL_MODELVIEW);

        RenderScene();

        objectsFound = glRenderMode(GL_RENDER);

        glMatrixMode(GL_PROJECTION);

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);

    if (objectsFound > 0) {
        unsigned int lowestDepth = selectBuffer[1];

        int selectedObject = selectBuffer[3];

        for(int i = 1; i < objectsFound; i++) {
            if(selectBuffer[(i * 4) + 1] < lowestDepth) {
                lowestDepth = selectBuffer[(i * 4) + 1];
                selectedObject = selectBuffer[(i * 4) + 3];
            }
        }
        return selectedObject;
    }
    return 0;
}
