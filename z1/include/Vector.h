#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include <cmath>
#include <iostream>

class Vector
{
    public:
        float x, y, z;

        Vector();
        Vector(float x, float y, float z);
        Vector(Vector p1, Vector p2);
        ~Vector();
        Vector(const Vector &v);
        void operator+=(const Vector& v);
        void add(Vector v);
        void sub(Vector v);
        void div(float f);
        void mag(float f);
        float length();
        void normalize();
        Vector dot(Vector v);
        float dotProduct(Vector v);
        Vector cross(Vector v);


};

#endif // VECTOR_H
