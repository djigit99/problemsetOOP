#include "quadrangularpyramid.h"
#include <iostream>

QuadrangularPyramid::QuadrangularPyramid(float w, float h,
                                         float xCord, float yCord, float zCord,
                                         QColor color) :
        Figure(PYRAMID, xCord, yCord, zCord, color), width(w), height(h) {

}

void QuadrangularPyramid::draw() {
    /* Translation */

    glPushName(ID);
    glPushMatrix();

    glTranslatef(xCord, yCord, zCord);

    /* Rotation */
    getNewCord();


    /* Lines drawing */

    glColor3f(0.f, 0.f, 0.f);
    glBegin(GL_LINES);
        for (int i = 1; i < 5; i++) {
            glVertex3f(new_cords[i].x(), new_cords[i].y(), new_cords[i].z());
            if (i < 4) {
                glVertex3f(new_cords[i+1].x(), new_cords[i+1].y(), new_cords[i+1].z());
            } else {
                glVertex3f(new_cords[1].x(), new_cords[1].y(), new_cords[1].z());
            }
            glVertex3f(new_cords[0].x(), new_cords[0].y(), new_cords[0].z());
            glVertex3f(new_cords[i].x(), new_cords[i].y(), new_cords[i].z());
        }

    glEnd();

    /* Drawing shape */

    glColor3ub(color.red(), color.green(), color.blue());
    glBegin(GL_QUADS);
        for (int i = 1; i <= 4; i++) {
            glVertex3f( new_cords[i].x(),  new_cords[i].y(),   new_cords[i].z());
        }
    glEnd();
    glBegin(GL_TRIANGLES);
        for (int i = 1; i <= 4; i++) {
            glVertex3f( new_cords[i].x(),  new_cords[i].y(),   new_cords[i].z());
            glVertex3f( new_cords[0].x(),  new_cords[0].y(),   new_cords[0].z());
            if (i < 4) {
                glVertex3f( new_cords[i+1].x(),  new_cords[i+1].y(),   new_cords[i+1].z());
            } else {
                glVertex3f( new_cords[1].x(),  new_cords[1].y(),   new_cords[1].z());
            }
        }
    glEnd();

    glPopMatrix();
    glPopName();
}

void QuadrangularPyramid::drawProjectionYZ() {
    glColor3ub(color.red(), color.green(), color.blue());

    QVector3D* new_cordsYZ = new QVector3D[5];
    for (int i = 0; i < 5; i++) {
        new_cordsYZ[i] = cords[i];
    }

    glPushMatrix();

    glTranslatef(0.f, yCord, zCord);

    rotateXAx(new_cordsYZ);
    rotateYAx(new_cordsYZ);
    rotateZAx(new_cordsYZ);

    glBegin(GL_TRIANGLES);
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int y = j + 1; y < 5; y++) {
                    glVertex3f( 0.f,  new_cordsYZ[i].y(),   new_cordsYZ[i].z());
                    glVertex3f( 0.f,  new_cordsYZ[j].y(),   new_cordsYZ[j].z());
                    glVertex3f( 0.f,  new_cordsYZ[y].y(),   new_cordsYZ[y].z());
                }
            }
        }
    glEnd();

    glPopMatrix();

    delete new_cordsYZ;
}

void QuadrangularPyramid::drawProjectionZX() {
    glColor3ub(color.red(), color.green(), color.blue());

    QVector3D* new_cordsZX = new QVector3D[5];
    for (int i = 0; i < 5; i++) {
        new_cordsZX[i] = cords[i];
    }

    glPushMatrix();

    glTranslatef(xCord, 0.f, zCord);

    rotateXAx(new_cordsZX);
    rotateYAx(new_cordsZX);
    rotateZAx(new_cordsZX);

    glBegin(GL_TRIANGLES);
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int y = j + 1; y < 5; y++) {
                    glVertex3f( new_cordsZX[i].x(),  0.f,   new_cordsZX[i].z());
                    glVertex3f( new_cordsZX[j].x(),  0.f,   new_cordsZX[j].z());
                    glVertex3f( new_cordsZX[y].x(),  0.f,   new_cordsZX[y].z());
                }
            }
        }
    glEnd();

    glPopMatrix();

    delete new_cordsZX;

}

void QuadrangularPyramid::drawProjectionXY() {
    glColor3ub(color.red(), color.green(), color.blue());

    QVector3D* new_cordsXY = new QVector3D[5];
    for (int i = 0; i < 5; i++) {
        new_cordsXY[i] = cords[i];
    }

    glPushMatrix();

    glTranslatef(xCord, yCord, 0.f);

    rotateXAx(new_cordsXY);
    rotateYAx(new_cordsXY);
    rotateZAx(new_cordsXY);

    glBegin(GL_TRIANGLES);
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int y = j + 1; y < 5; y++) {
                    glVertex3f( new_cordsXY[i].x(),  new_cordsXY[i].y(),   0.f);
                    glVertex3f( new_cordsXY[j].x(),  new_cordsXY[j].y(),   0.f);
                    glVertex3f( new_cordsXY[y].x(),  new_cordsXY[y].y(),   0.f);
                }
            }
        }
    glEnd();

    glPopMatrix();

    delete new_cordsXY;

}

void QuadrangularPyramid::getNewCord() {
    for (int i = 0; i < 5; i++) {
        new_cords[i] = cords[i];
    }

    rotateXAx(new_cords);
    rotateYAx(new_cords);
    rotateZAx(new_cords);
}

void QuadrangularPyramid::rotateXAx(QVector3D* new_coord) {
    for (int i = 0; i < 5; i++) {
        float x = new_coord[i].x();
        float y = new_coord[i].y();
        float z = new_coord[i].z();
        new_coord[i].setX(x);
        new_coord[i].setY(cos(angleX * M_PI / 180.) * y - sin(angleX * M_PI / 180.) * z );
        new_coord[i].setZ(sin(angleX * M_PI / 180.) * y + cos(angleX * M_PI / 180.) * z );
    }
}

void QuadrangularPyramid::rotateYAx(QVector3D* new_coord) {
    for (int i = 0; i < 5; i++) {
        float x = new_coord[i].x();
        float y = new_coord[i].y();
        float z = new_coord[i].z();
        new_coord[i].setX(cos(angleY * M_PI / 180.) * x + sin(angleY * M_PI / 180.) * z);
        new_coord[i].setY(y);
        new_coord[i].setZ(-sin(angleY * M_PI / 180.) * x + cos(angleY * M_PI / 180.) * z);
    }
}

void QuadrangularPyramid::rotateZAx(QVector3D* new_coord) {
    for (int i = 0; i < 5; i++) {
        float x = new_coord[i].x();
        float y = new_coord[i].y();
        float z = new_coord[i].z();
        new_coord[i].setX(cos(angleZ * M_PI / 180.) * x - sin(angleZ * M_PI / 180.) * y);
        new_coord[i].setY(sin(angleZ * M_PI / 180.) * x + cos(angleZ * M_PI / 180.) * y);
        new_coord[i].setZ(z);
    }
}

void QuadrangularPyramid::setWidth(float width) {
    this->width = width;
}

float QuadrangularPyramid::getHeight(){
    return height;
}

float QuadrangularPyramid::getWidth(){
    return width;
}

void QuadrangularPyramid::setHeight(float height) {
    this->height = height;
}

void QuadrangularPyramid::updateSizeArray() {
    cords[0] = {0.f, 0.f, 0.f};
    cords[1] = {-width / 2.f,  -height,   width / 2.f};
    cords[2] = {width / 2.f,  -height,   width / 2.f};
    cords[3] = {width / 2.f,  -height,  -width / 2.f};
    cords[4] = {-width / 2.f,  -height,  -width / 2.f};
}


