#include <iostream>
#include "Vector.h"
#include "Matrix4.h"
#include "Quaternion.h"

int main() {
    Quaternion q1(1.f, Vector(1, 2, 3));
    Quaternion q2(3.f, Vector(4, 5, 6));
    Vector v1(-1, -1, -1);
    std::cout
            << "kwaternion 1: "
            << q1
            << "\nkwaternion 2: "
            << q2
            << "\nDodawanie: "
            << q1 + q2
            << "\nOdejmowanie: "
            << q1 - q2
            << "\nMnozenie q1 * q2: "
            << q1 * q2
            << "\nMnozenie q2 * q1: "
            << q2 * q1
            << "\nDzielenie: "
            << q1 / q2
            << "\n punktu (-1, -1, -1) o 270 stopni: "
            << v1.rotateByQuaternion(270, Vector(1, 0, 0));



    return 0;
}