#ifndef MATMA_MATRIX4_H
#define MATMA_MATRIX4_H


#include "Vector.h"

class Matrix4 {
    float elements[16];
    Matrix4() {}
    Matrix4(float a11, float a12, float a13, float a14,
            float a21, float a22, float a23, float a24,
            float a31, float a32, float a33, float a34,
            float a41, float a42, float a43, float a44 );

    Matrix4(const float * f);
    Matrix4(const Matrix4 &mat);
    ~Matrix4() {}

    //dzialania
    Matrix4 operator+(const Matrix4& v) const;

    Matrix4 operator-(const Matrix4& v) const;

    Matrix4 operator*(const float f) const;

    Matrix4 operator/(const float f) const;

    Matrix4 operator*(const Matrix4& v) const;

    void LoadIdentity(void);

    void invertMatrix();

    Matrix4 getInverseOfMatrix(const Matrix4& v) const;

    Matrix4 getTransposeOfMatrix(const Matrix4 v) const;

    void transposeMatrix();

    //operacje na macierzach
    void setTranslationPart(const Vector& translation);
    void setScalePart(const Vector& scale);
    void setScalePartUniform(const float scaleFactor);

    void setRotationAxis(const double angle);
    void setRotationX(const double angle);
    void setRotationY(const double angle);
    void setRotationZ(const double angle);
};


#endif //MATMA_MATRIX4_H
