#include <cstring>
#include <stdexcept>
#include "Matrix4.h"

Matrix4::Matrix4(float a11, float a12, float a13, float a14,
        float a21, float a22, float a23, float a24,
        float a31, float a32, float a33, float a34,
        float a41, float a42, float a43, float a44 ) {
    elements[0] = a11;
    elements[1] = a12;
    elements[2] = a13;
    elements[3] = a14;
    elements[4] = a21;
    elements[5] = a22;
    elements[6] = a23;
    elements[7] = a24;
    elements[8] = a31;
    elements[9] = a32;
    elements[10] = a33;
    elements[11] = a34;
    elements[12] = a41;
    elements[13] = a42;
    elements[14] = a43;
    elements[15] = a44;
}
Matrix4::Matrix4(const float * f) {
    memcpy(elements, f, 16*sizeof(float));
}

Matrix4::Matrix4(const Matrix4 &mat) {
    memcpy(elements, mat.elements, 16*sizeof(float));
}

Matrix4 Matrix4::operator+(const Matrix4 &w) const {
    return Matrix4(elements[0]+w.elements[0], elements[1]+w.elements[1], elements[2]+w.elements[2], elements[3]+w.elements[3],
                   elements[4]+w.elements[4], elements[5]+w.elements[5], elements[6]+w.elements[6], elements[7]+w.elements[7],
                   elements[8]+w.elements[8], elements[9]+w.elements[9], elements[10]+w.elements[10], elements[11]+w.elements[11],
                   elements[12]+w.elements[12], elements[13]+w.elements[13], elements[14]+w.elements[14], elements[15]+w.elements[15]);
}

Matrix4 Matrix4::operator-(const Matrix4 &w) const {
    return Matrix4(elements[0]-w.elements[0], elements[1]-w.elements[1], elements[2]-w.elements[2], elements[3]-w.elements[3],
                   elements[4]-w.elements[4], elements[5]-w.elements[5], elements[6]-w.elements[6], elements[7]-w.elements[7],
                   elements[8]-w.elements[8], elements[9]-w.elements[9], elements[10]-w.elements[10], elements[11]-w.elements[11],
                   elements[12]-w.elements[12], elements[13]-w.elements[13], elements[14]-w.elements[14], elements[15]-w.elements[15]);
}

Matrix4 Matrix4::operator*(const float f) const {
    return Matrix4(elements[0]*f, elements[1]*f, elements[2]*f, elements[3]*f,
                   elements[4]*f, elements[5]*f, elements[6]*f, elements[7]*f,
                   elements[8]*f, elements[9]*f, elements[10]*f, elements[11]*f,
                   elements[12]*f, elements[13]*f, elements[14]*f, elements[15]*f);
}

Matrix4 Matrix4::operator/(const float f) const {
    if (f == 0)
        throw std::invalid_argument("Dzielenie przez 0");

    return Matrix4(elements[0]/f, elements[1]/f, elements[2]/f, elements[3]/f,
                   elements[4]/f, elements[5]/f, elements[6]/f, elements[7]/f,
                   elements[8]/f, elements[9]/f, elements[10]/f, elements[11]/f,
                   elements[12]/f, elements[13]/f, elements[14]/f, elements[15]/f);
}

Matrix4 Matrix4::operator*(const Matrix4& v) const {
    //mnozenie macierzy
}