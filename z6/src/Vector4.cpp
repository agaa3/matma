//
// Created by Agata on 2022-11-17.
//

#include "Vector4.h"
#include "Vector.h"

Vector4::Vector4() {
    //ctor
}

Vector4::~Vector4() {
    //dtor
}

Vector4::Vector4(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4::Vector4(const Vector4 &v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}

Vector4::Vector4(const Vector &v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = 1.0f;
}

Vector4 Vector4::operator+(const Vector4 &w) const {
    Vector4 res(0, 0, 0, 0);
    res.x = w.x + this->x;
    res.y = w.y + this->y;
    res.z = w.z + this->z;
    res.w = w.w + this->w;

    return res;
}

Vector4 Vector4::operator-(const Vector4 &w) const {
    Vector4 res(0, 0, 0, 0);
    res.x = this->x - w.x;
    res.y = this->y - w.y;
    res.z = this->z - w.z;
    res.w = this->w - w.w;

    return res;
}

Vector4 Vector4::operator*(const float &k) const {
    Vector4 res(0, 0, 0, 0);
    res.x = this->x * k;
    res.y = this->y * k;
    res.z = this->z * k;
    res.w = this->w * k;

    return res;
}

Vector4 Vector4::operator/(const float &k) const {
    if (k == 0)
        throw std::invalid_argument("Dzielenie przez 0");

    Vector4 res(0, 0, 0, 0);
    res.x = this->x / k;
    res.y = this->y / k;
    res.z = this->z / k;
    res.w = this->w / k;

    return res;
}

float Vector4::length() const {
    return (float) sqrt(pow(this->x, 2) +
                        pow(this->y, 2) +
                        pow(this->z, 2) +
                        pow(this->w, 2));
}

Vector4 Vector4::normalize() const {
    float n = this->length();
    if (n == 0)
        throw std::invalid_argument("Dzielenie przez 0");
    return this->operator/(n);
}

std::ostream& operator<<(std::ostream& stream, const Vector4& v) {
    stream << "[ " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "]";
    return stream;
}