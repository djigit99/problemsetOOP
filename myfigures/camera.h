#ifndef CAMERA_H
#define CAMERA_H


#include <glm/glm.hpp>


class Camera {

    static const float MOVEMENT_SPEED;
    static const float ROTATIONAL_SPEED;

    glm::vec3 position;
    glm::vec3 viewDirection;
    glm::vec3 UP;

public:
    Camera();

    void moveForward();
    void moveBackward();
    void strafeLeft();
    void strafeRight();
    void moveUp();
    void moveDown();
    glm::vec3 getPosition() const { return position; }
    glm::vec3 getViewDirection() const { return viewDirection; }
    glm::vec3 getUP() const {return UP;}

};

#endif // CAMERA_H
