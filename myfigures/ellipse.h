#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QColor>
#include "figure.h"

class Ellipse : public Figure {
    float width;
    float height;
    QColor color;
public:
    Ellipse();
    Ellipse(float, float, float, float, float, QColor);

    void draw();
    void drawProjectionXY(){}
    void drawProjectionYZ(){}
    void drawProjectionZX(){}
    void getNewCord() {}

    void setWidth(float);
    void setHeight(float);
    float getWidth();
    float getHeight();
};

#endif // ELLIPSE_H
