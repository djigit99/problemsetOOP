#include "ellipse.h"
#include <GL/glu.h>

Ellipse::Ellipse() : Figure() {

}
Ellipse::Ellipse(float xCord, float yCord, float zCord, float width, float height,
                 QColor color) :
        Figure(SPHERE, xCord, yCord, zCord, color), width(width), height(height) {

}

void Ellipse::draw() {

     glColor3ub(color.red(), color.green(), color.blue());
     glPushName(ID);

     glPushMatrix();

     /* Translation */
     glTranslatef(xCord, yCord, zCord);

     GLUquadricObj* m_qObj = gluNewQuadric();
     glScaled(0.5f, 0.6f, 0.7f);
     gluSphere(m_qObj, width, 50, 50);

     glPopMatrix();

     gluDeleteQuadric(m_qObj);
     glPopName();
}

void Ellipse::setWidth(float width) {
    this->width = width;
}

void Ellipse::setHeight(float height) {
    this->height = height;
}

float Ellipse::getWidth() {
    return width;
}

float Ellipse::getHeight() {
    return height;
}
