#ifndef SPHERE_H
#define SPHERE_H

#include "figure.h"

#define SPHERE_ID 102

class Sphere : public Figure {
    float radius;
    float cordsCenter[3] = {0.f, 0.f, 0.f};
public:
    Sphere();
    Sphere(float, float, float, QColor, float);

    void draw();
    void drawProjectionXY();
    void drawProjectionYZ();
    void drawProjectionZX();

    void setRadius(float);
    float getRadius();
};

#endif // SPHERE_H
