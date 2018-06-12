#ifndef FIGURE_H
#define FIGURE_H

#include <QColor>

enum TYPE {
    PYRAMID,
    SPHERE
};

class Figure {

protected:
    const unsigned int ID;
    static unsigned int ID_MAX;

    TYPE type;

    float xCord;
    float yCord;
    float zCord;

    float angleX;
    float angleY;
    float angleZ;

    QColor color;

    bool selected;

public:
    Figure();
    Figure(TYPE, float, float, float);
    Figure(TYPE, float, float, float, QColor&);
    ~Figure();

    virtual void draw() = 0;
    virtual void drawProjectionXY() = 0;
    virtual void drawProjectionYZ() = 0;
    virtual void drawProjectionZX() = 0;
    virtual void getNewCord();


    void incAngleX(float);
    void incAngleY(float);
    void incAngleZ(float);

    void incXCord(float);
    void incYCord(float);
    void incZCord(float);

    unsigned int getId();

    void setColor(QColor);
    QColor getColor();

    float getXCord();
    float getYCord();
    float getZCord();

    float getXAngle();
    float getYAngle();
    float getZAngle();

    void setXAngle(float);
    void setYAngle(float);
    void setZAngle(float);

    TYPE getType();

    bool isSelected();
    bool reSelected();
};

#endif // FIGURE_H
