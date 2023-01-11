//
// Created by Agata on 2022-11-17.
//

#ifndef MATMA_VECTOR4_H
#define MATMA_VECTOR4_H


#include <ostream>
#include "Vector.h"

class Vector4 {
public:
    float x, y, z, w;

    Vector4();

    Vector4(float x, float y, float z, float w);

    ~Vector4();

    Vector4(const Vector4 &v);
    Vector4(const Vector &v);
    friend std::ostream& operator<<(std::ostream& stream, const Vector4& v);

    // dodawanie i odejmowanie wektorów
    Vector4 operator+(const Vector4& v) const;

    Vector4 operator-(const Vector4& v) const;

    // mnożenie/dzielnie
    Vector4 operator/(const float& f) const;

    Vector4 operator*(const float& k) const;

    // długość
    float length() const;

    // normalizacja
    Vector4 normalize() const;

};


#endif //MATMA_VECTOR4_H
