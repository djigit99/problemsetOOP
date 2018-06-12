#ifndef QUADRANGULARPYRAMID_H
#define QUADRANGULARPYRAMID_H

#include "figure.h"
#include <GL/glu.h>
#include <QVector3D>
#include <cmath>

class QuadrangularPyramid : public Figure {

    float width;
    float height;
    QVector3D cords[5] = { {0.f, 0.f, 0.f}, {-width / 2.f,  -height,   width / 2.f},
                         {width / 2.f,  -height,   width / 2.f}, {width / 2.f,  -height,  -width / 2.f},
                         {-width / 2.f,  -height,  -width / 2.f} };
    QVector3D new_cords[5];

public:
    QuadrangularPyramid(float w, float h,
                        float xCord, float yCord, float zCord,
                        QColor color);

    void draw();
    void drawProjectionXY();
    void drawProjectionYZ();
    void drawProjectionZX();
    void getNewCord();

    void rotateXAx(QVector3D *);
    void rotateYAx(QVector3D *);
    void rotateZAx(QVector3D *);

    void setHeight(float);
    void setWidth(float);

    float getHeight();
    float getWidth();

    void updateSizeArray();


};

#endif // QUADRANGULARPYRAMID_H
