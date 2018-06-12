#include "figure.h"
#include <GL/glu.h>

Figure::Figure() : ID(ID_MAX++) {
}

Figure::Figure(TYPE type, float xCord, float yCord, float zCord) :
        ID(ID_MAX++),type(type),
        xCord(xCord), yCord(yCord), zCord(zCord),
        angleX(0.f), angleY(0.f), angleZ(0.f), selected(false) {
}

Figure::Figure(TYPE type, float xCord, float yCord, float zCord,
                    QColor &color) :
        ID(ID_MAX++),
        type(type),
        xCord(xCord), yCord(yCord), zCord(zCord),
        angleX(0.f), angleY(0.f), angleZ(0.f),
        color(color), selected(false) {

}

Figure::~Figure() {
    ID_MAX--;
}


void Figure::incAngleX(float angle) {
    angleX += angle;
    if (angleX >= 360) {
        angleX -= 360;
    } else if (angleX <= -360) {
        angleX += 360;
    }
}

void Figure::incAngleY(float angle) {
    angleY += angle;
    if (angleY >= 360) {
        angleY -= 360;
    } else if (angleY <= -360) {
        angleY += 360;
    }
}

void Figure::incAngleZ(float angle) {
    angleZ += angle;
    if (angleZ >= 360) {
        angleZ -= 360;
    } else if (angleZ <= -360) {
        angleZ += 360;
    }
}

void Figure::incXCord(float del) {
    xCord += del;
}

void Figure::incYCord(float del) {
    yCord += del;
}

void Figure::incZCord(float del) {
    zCord += del;
}

unsigned int Figure::getId() {
    return ID;
}

void Figure::setColor(QColor color) {
    this->color = color;
}

QColor Figure::getColor(){
    return color;
}

float Figure::getXCord() {
    return xCord;
}

float Figure::getYCord() {
    return yCord;
}

float Figure::getZCord() {
    return zCord;
}

float Figure::getXAngle() {
    return angleX;
}
float Figure::getYAngle() {
    return angleY;
}
float Figure::getZAngle() {
    return angleZ;
}

void Figure::setXAngle(float angle) {
    this->angleX = angle;
}

void Figure::setYAngle(float angle) {
    this->angleY = angle;
}

void Figure::setZAngle(float angle) {
    this->angleZ = angle;
}

TYPE Figure::getType() {
    return type;
}

bool Figure::isSelected() {
    return selected;
}

bool Figure::reSelected() {
    selected = (selected == false);
    return selected;
}

void Figure::getNewCord() {

}

unsigned int Figure::ID_MAX = 100;
