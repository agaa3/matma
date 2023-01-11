//
// Created by Agata on 2023-01-10.
//

#include "Camera.h"

Camera::Camera(const Vector &position, const Vector &direction, const Vector &up) : position(position), direction(direction), up(up) {
    this->radius = sqrt(position.x*position.x + position.y*position.y + position.z*position.z);
}

Camera::Camera(float radius) : radius(radius) {
    this->position = Vector(0, 0, radius);
    this->direction  = Vector(0, 0, -1);
    this->up = Vector(0,1, 0);
}

void Camera::rotateX(float angle) {
    position = position.rotateByQuaternion(angle, Vector(1, 0, 0));
    direction = direction.rotateByQuaternion(angle, Vector(1, 0, 0));
    direction = direction.normalize();
    up = up.rotateByQuaternion(angle, Vector(1, 0, 0));
    up = up.normalize();
}

void Camera::rotateY(float angle) {
    position = position.rotateByQuaternion(angle, Vector(0, 1, 0));
    direction = direction.rotateByQuaternion(angle, Vector(0, 1, 0));
    direction = direction.normalize();
    up = up.rotateByQuaternion(angle, Vector(0, 1, 0));
    up = up.normalize();
}

void Camera::rotateZ(float angle) {
    position = position.rotateByQuaternion(angle, Vector(0, 0, 1));
    direction = direction.rotateByQuaternion(angle, Vector(0, 0, 1));
    direction = direction.normalize();
    up = up.rotateByQuaternion(angle, Vector(0, 0, 1));
    up = up.normalize();
}

void Camera::rotateAxis(float angle, Vector axis) {
    position = position.rotateByQuaternion(angle, axis);
    direction = direction.rotateByQuaternion(angle, axis);
    direction = direction.normalize();
    up = up.rotateByQuaternion(angle, axis);
    up = up.normalize();
}