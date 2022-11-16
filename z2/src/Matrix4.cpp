#include <cstring>
#include <stdexcept>
#include "Matrix4.h"
#include "../include/Matrix4.h"


Matrix4::Matrix4(float a11, float a12, float a13, float a14,
                 float a21, float a22, float a23, float a24,
                 float a31, float a32, float a33, float a34,
                 float a41, float a42, float a43, float a44) {
	elements[0][0] = a11;elements[0][1] = a12;elements[0][2] = a13;elements[0][3] = a14;
	elements[1][0] = a21;elements[1][1] = a22;elements[1][2] = a23;elements[1][3] = a24;
	elements[2][0] = a31;elements[2][1] = a32;elements[2][2] = a33;elements[2][3] = a34;
	elements[3][0] = a41;elements[3][1] = a42;elements[3][2] = a43;elements[3][3] = a44;
}

Matrix4::Matrix4(const float elem[4][4]) {
	memcpy(&elements[0][0], &elem[0][0], 4 * 4 * sizeof(elem[0][0]));
}

// ładowane wierszami
Matrix4::Matrix4(const float *f) {
	for (int i = 0; i < this->size; ++i)
		for (int j = 0; j < this->size; ++j)
			elements[i][j] = f[i * this->size + j];
}

Matrix4::Matrix4(const Matrix4 &mat) {
	for (int i = 0; i < this->size; ++i)
		for (int j = 0; j < this->size; ++j)
			this->elements[i][j] = mat.elements[i][j];
}

Matrix4 Matrix4::operator+(const Matrix4 &w) const {
	float f[4][4];
	for (int i = 0; i < this->size; ++i)
		for (int j = 0; j < this->size; ++j)
			f[i][j] = w.elements[i][j] + elements[i][j];

	return Matrix4(f);
}

Matrix4 Matrix4::operator-(const Matrix4 &w) const {
	float f[4][4];
	for (int i = 0; i < this->size; ++i)
		for (int j = 0; j < this->size; ++j)
			f[i][j] = elements[i][j] - w.elements[i][j];

	return Matrix4(f);
}

Matrix4 Matrix4::operator*(const float f) const {
	float res[4][4];
	for (int i = 0; i < this->size; ++i)
		for (int j = 0; j < this->size; ++j)
			res[i][j] = f * elements[i][j];

	return Matrix4(res);
}

Matrix4 Matrix4::operator/(const float f) const {
	if (f == 0)
		throw std::invalid_argument("Dzielenie przez 0");

	float res[4][4];
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[i][j] = elements[i][j] / f;

	return Matrix4(res);
}

Matrix4 Matrix4::operator*(const Matrix4 &v) const {
	float res[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				res[i][j] += this->elements[i][k] * v.elements[k][j];
			}
		}
	}

	return Matrix4(res);
}

void Matrix4::setTranslationPart(const Vector &translation) {
	elements[0][3] = translation.x;
	elements[1][3] = translation.y;
	elements[2][3] = translation.z;
}

void Matrix4::setScalePart(const Vector &scale) {
	elements[0][0] = scale.x;
	elements[1][1] = scale.y;
	elements[2][2] = scale.z;
	elements[3][3] = 1;
}

void Matrix4::setScalePartUniform(const float scaleFactor) {
	elements[0][0] = scaleFactor;
	elements[1][1] = scaleFactor;
	elements[2][2] = scaleFactor;
	elements[3][3] = 1;
}

void Matrix4::setRotationAxis(const double angle, const Vector& axis) {
	this->makeOne();
	float sinAngle = (float)sin(M_PI * angle / 180);
	float cosAngle = (float)cos(M_PI * angle / 180);
	float oneMinus = 1.0f - cosAngle;

	Vector u = axis.normalize();

	elements[0][0] = u.x * u.x + cosAngle*(1 - (u.x*u.x));
	elements[1][0] = u.x * u.y * oneMinus - sinAngle*u.z;
	elements[2][0] = u.x * u.z * oneMinus + sinAngle*u.y;

	elements[0][1] = u.x * u.y * oneMinus - sinAngle*u.z;
	elements[1][1] = u.x * u.y + cosAngle*(1 - u.y*u.y);
	elements[2][1] = u.y * u.z * oneMinus - sinAngle*u.x;

	elements[0][2] = u.x * u.z * oneMinus - sinAngle * u.y;
	elements[0][2] = u.y * u.z * oneMinus + sinAngle * u.x;
	elements[0][2] = u.z * u.z + cosAngle*(1 - u.z*u.z);

}

void Matrix4::setRotationX(const double angle) {
	this->makeOne();

	elements[1][1] = (float)cos(M_PI*angle/180);
	elements[1][2] = (float)sin(M_PI*angle/180);

	elements[2][1] = - elements[1][1];
	elements[2][2] = elements[1][2];
}

void Matrix4::setRotationY(const double angle) {
	this->makeOne();
	elements[0][0] = (float)cos(M_PI*angle/180);
	elements[0][2] = (float)sin(M_PI*angle/180);

	elements[2][0] = - elements[0][0];
	elements[2][2] = elements[0][2];
}

void Matrix4::setRotationZ(const double angle) {
	this->makeOne();
	elements[0][0] = (float)cos(M_PI*angle/180);
	elements[0][1] = (float)sin(M_PI*angle/180);

	elements[1][0] = - elements[0][0];
	elements[1][1] = elements[0][1];
}

Matrix4 Matrix4::inverseMatrix(const Matrix4 &v) {
	float det = v.det();
	if (det == 0)
		throw std::logic_error("dzielenie przez zero");

	return transposeMatrix(v)/ det;
}

Matrix4 Matrix4::transposeMatrix(const Matrix4 v) {
	float res[4][4];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			res[i][j] = v.elements[j][i];

	return Matrix4(res);
}

Matrix4 Matrix4::makeIdentity(void) {
	Matrix4 m;
	m.elements[0][0] = 1.0f;
	m.elements[1][1] = 1.0f;
	m.elements[2][2] = 1.0f;
	m.elements[3][3] = 1.0f;
	return m;
}

std::ostream &operator<<(std::ostream &stream, const Matrix4 &v) {
	for (int i = 0; i < 4; ++i) {
		stream << "[ ";
		for (int j = 0; j < 3; ++j)
			stream << v.elements[i][j] << ", ";
		stream << v.elements[i][3] << " ]\n";
	}
	return stream;
}

float Matrix4::det(void) const {
	float c, r=1;
	Matrix4 support(this->elements);
	for(int i = 0; i < 4; i++) {
		for(int k = i+1; k < 4; k++) {
			c = support.elements[k][i] / support.elements[i][i];
			for(int j = i; j < 4; j++)
				support.elements[k][j] = support.elements[k][j] - c*support.elements[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
		r *= support.elements[i][i];
	return r;
}

void Matrix4::makeOne(void) {
	memcpy(&elements[0][0], &makeIdentity().elements[0][0], 4 * 4 * sizeof(elements[0][0]));

}
