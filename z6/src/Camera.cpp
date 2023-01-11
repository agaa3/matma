//
// Created by Agata on 2023-01-10.
//

#include "Camera.h"

Camera::Camera(const Vector &position, const Vector &direction, const Vector &up) : position(position), direction(direction), up(up) {
    this->radius = sqrt(position.x*position.x + position.y*position.y + position.z*position.z);
    //this->right = this->direction.cross(up);
}

void Camera::rotateY(float angle) {
    Vector axis = Vector(sin(angle * M_PI / 180), 0, cos(angle * M_PI / 180));

    position.x = sin(angle * M_PI / 180)*radius;
    position.z = cos(angle * M_PI / 180)*radius;
    direction = Vector(-position.x, -position.y, -position.z);
    direction = direction.normalize();

    right.x = cos(angle * M_PI / 180);
    right.z = -sin(angle * M_PI / 180);
    if(right.y== -0) right.y = 0;
    right = right.normalize();
    up = right.cross(direction);
//    up.x = -sin(angle * M_PI / 180);
//    up.z = -cos(angle * M_PI / 180);
//    up = up.normalize();
}

Camera::Camera(float radius) : radius(radius) {
    this->position = Vector(0, 0, radius);
    this->direction  = Vector(0, 0, -1);
    this->up = Vector(0,1, 0);
    this->right = direction.cross(up);
    this->right = this->right.normalize();

}

void Camera::rotateX(float angle) {
    position.y = sin(angle * M_PI / 180)*radius;
    position.z = cos(angle * M_PI / 180)*radius;
    direction = Vector(-position.x/radius, -position.y/radius, -position.z/radius);
    direction = direction.normalize();
    if(direction.x == -0) direction.x = 0;
    up = right.cross(direction);
    up = up.normalize();
//    up.y = position.z;
//    up.z = -position.y;
//    up = up.normalize();
}

void Camera::rotateZ(float angle) {
    up.x = sin(angle * M_PI / 180);
    up.y = cos(angle * M_PI / 180);
    up = up.normalize();
    right = direction.cross(up);
}
