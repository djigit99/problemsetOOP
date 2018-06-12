#include "camera.h"
#include <glm/gtx/transform.hpp>

const float Camera::MOVEMENT_SPEED = 1.f;
const float Camera::ROTATIONAL_SPEED = 0.1f;


Camera::Camera() :
    position(0.f, 0.f, -50.f),
    viewDirection(0.f, 0.f, 1.f),
    UP(0.0f, 1.0f, 0.0f) {
}

void Camera::moveForward() {
    position += MOVEMENT_SPEED * viewDirection;
}

void Camera::moveBackward() {
    position += -MOVEMENT_SPEED * viewDirection;
}

void Camera::strafeLeft() {
    viewDirection = glm::mat3(glm::rotate(ROTATIONAL_SPEED , UP)) * viewDirection;
}

void Camera::strafeRight() {
    viewDirection = glm::mat3(glm::rotate(-ROTATIONAL_SPEED , UP)) * viewDirection;
}

void Camera::moveUp() {
    position += MOVEMENT_SPEED * UP;
}

void Camera::moveDown() {
    position += -MOVEMENT_SPEED * UP;
}
