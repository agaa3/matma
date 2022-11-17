#include <iostream>
#include "Vector.h"
#include "Matrix4.h"

int main() {
    // 1 Dodawanie
    float tmp[16] = {7, 5, -5, 1,
                       -5, 3, 7, 15,
                       1, -9, 3, 7,
                       0, 0, 0, 0};
    Matrix4 m1;
    m1.LoadIdentity();
    Matrix4 m2(tmp);
    Matrix4 m3(m2 + m1 / 2);

    float tA[16] = {1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1};
    Matrix4 A(tA);
    float tB[16] = {3, 4, 5, 2, 1, 2, 3, 1, 4, 4, 1, 2, 5, 4, 1, 2};
    Matrix4 B(tB);

    std::cout
            << "m1:\n" << m1 << "m2:\n" << m2 << "Result: m1 + m2\n" << m1 + m2 << "\n\n"
            << "m1:\n" << m1 << "m2:\n" << m2 << "Result: m1 - m2\n" << m1 - m2 << "\n\n"
            << "m2:\n" << m2 << "Result: m2 * 2\n" << m2 * 2 << "\n\n"
            << "m3:\n" << m3 << "Result: m3 / 2\n" << m3 / 2 << "\n\n"
            << "\nBRAK PRZEMIENNOSCI MNOZENIA:\n"
            << "A:\n" << A << "B:\n" << B
            << "Result: A * B\n" << A * B << "\n"
            << "Result: B * A\n" << B * A << "\n\n"
            << "A:\n" << A << "det(A): " << A.det(A) << "\n"
            << "B:\n" << B << "det(B): " << B.det(B) << "\n";

    float tC[16] = {5, 4, 5, 2, 11, 33, 3, 1, 4, 4, 1, 2, 5, 4, 2, 2};
    Matrix4 C(tC);
    std::cout << "C:\n" << C << "det(C): " << C.det(C) << "\n"
    << "\nInverse of C:\n" << C.getInverseOfMatrix()
    << "C * C^-1\n" << C*(C.getInverseOfMatrix())
    << "\nm2:\n" << m2 << "Transpose:\n" << m2.getTransposeOfMatrix() << "\n";


    Matrix4 m11;
    m11.LoadIdentity();
    m11.setTranslationPart(Vector(1, 2, 3));

    Matrix4 m12;
    m12.LoadIdentity();
    m12.setScalePart(Vector(-3, 2, 1));

    Matrix4 m13;
    m13.LoadIdentity();
    m13.setScalePartUniform(3);

    Matrix4 m21;
    m21.LoadIdentity();
    m21.setRotationX(90);

    Matrix4 m22;
    m22.LoadIdentity();
    m22.setRotationY(90);

    Matrix4 m23;
    m23.LoadIdentity();
    m23.setRotationZ(90);

    Matrix4 m33;
    m33.LoadIdentity();
    Vector v = Vector(1.0f, 2.0f, -1.0f);
    m33.setRotationAxis(90, v);

    std::cout << "Operacje zrealizowane na macierzy jednostowej:\n" << m1
              << "Translation Part:\n" << m11 << "\n"
              << "Scale Part:\n" << m12 << "\n"
              << "Scale Part Uniform:\n" << m13 << "\n"
              << "Rotation X (90 stopni):\n" << m21 << "\n"
              << "Rotation Y (90 stopni):\n" << m22 << "\n"
              << "Rotation Z (90 stopni):\n" << m23 << "\n"
              << "Rotation Axis (90 stopni):\n" << "axis: " << v << "\nResult: \n" << m33 << "\n\n";

    // obrót [1, 0, 0, 1] o oś Y o 90stp
    float obrotT[16] = {1, 0, 0, 1,
                          0, 0, 0, 0,
                          0, 0, 0, 0,
                          0, 0, 0, 0};

    Matrix4 obrot(obrotT);
    Matrix4 przeksztalcenie;
    przeksztalcenie.LoadIdentity();
    przeksztalcenie.setRotationY(90);

    Matrix4 result;
    result = przeksztalcenie *obrot;
    Vector4 v1(1, 0, 0, 1);
    Vector4 res1 = przeksztalcenie*v1;
    std::cout
            << "Obrot wektora: "
            << v1
            << "\nmacierz obrotu:\n"
            <<przeksztalcenie
            <<"WYNIK: "
            << res1 << "\n";


    return 0;
}