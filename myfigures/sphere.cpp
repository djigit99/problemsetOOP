#include "sphere.h"
#include "figure.h"
#include <GL/glu.h>
#include <cmath>

Sphere::Sphere() : Figure() {

}
Sphere::Sphere(float xCord, float yCord, float zCord, QColor color, float radius) :
        Figure(SPHERE, xCord, yCord, zCord, color), radius(radius) {

}

void Sphere::draw() {

     glColor3ub(color.red(), color.green(), color.blue());
     glPushName(ID);

     glPushMatrix();

     /* Translation */
     glTranslatef(xCord, yCord, zCord);

     GLUquadricObj* m_qObj = gluNewQuadric();
     gluSphere(m_qObj, radius, 50, 50);

     glPopMatrix();

     gluDeleteQuadric(m_qObj);
     glPopName();
}

void Sphere::drawProjectionYZ() {
    glColor3ub(color.red(), color.green(), color.blue());
    const float PI = 3.14;

    glPushMatrix();

    glTranslatef(0.f, yCord, zCord);

    glBegin(GL_POLYGON);
        for ( int i = 0; i <= 360; i++) {
            glVertex3f( 0.f, sin(i * PI / 180 ) * radius, cos( i * PI / 180 ) * radius);
        }
    glEnd();

    glPopMatrix();
}

void Sphere::drawProjectionZX() {
    glColor3ub(color.red(), color.green(), color.blue());
    const float PI = 3.14;

    glPushMatrix();

    glTranslatef(xCord, 0.f, zCord);

    glBegin(GL_POLYGON);
        for ( int i = 0; i <= 360; i++) {
            glVertex3f( sin(i * PI / 180 ) * radius, 0.f, cos( i * PI / 180 ) * radius);
        }
    glEnd();

    glPopMatrix();
}

void Sphere::drawProjectionXY() {
    glColor3ub(color.red(), color.green(), color.blue());
    const float PI = 3.14;

    glPushMatrix();

    glTranslatef(xCord, yCord, 0.f);

    glBegin(GL_POLYGON);
        for ( int i = 0; i <= 360; i++) {
            glVertex3f( sin(i * PI / 180 ) * radius, cos( i * PI / 180 ) * radius, 0);
        }
    glEnd();

    glPopMatrix();
}


void Sphere::setRadius(float r) {
    radius = r;
}

float Sphere::getRadius() {
    return radius;
}
