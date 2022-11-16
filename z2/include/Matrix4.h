#ifndef MATMA_MATRIX4_H
#define MATMA_MATRIX4_H

#include "Vector.h"

class Matrix4 {

private:
	float elements[4][4];
	const int size = 4;
	void makeOne(void);

public:
	Matrix4() {
		memset(elements, 0, 16 * sizeof(float));
	}

	Matrix4(const float elem[4][4]);

	Matrix4(float a11, float a12, float a13, float a14,
	        float a21, float a22, float a23, float a24,
	        float a31, float a32, float a33, float a34,
	        float a41, float a42, float a43, float a44);

	Matrix4(const float *f);

	// copy constructor
	Matrix4(const Matrix4 &mat);

	~Matrix4() {}

	//dzialania na liczbach
	Matrix4 operator*(const float f) const;
	Matrix4 operator/(const float f) const;

	// działania na macierzach
	Matrix4 operator+(const Matrix4 &v) const;
	Matrix4 operator-(const Matrix4 &v) const;
	Matrix4 operator*(const Matrix4 &v) const;

	friend std::ostream& operator<<(std::ostream& stream, const Matrix4& v);

	// przekształcenia
	static Matrix4 makeIdentity(void);
	static Matrix4 inverseMatrix(const Matrix4 &v);
	static Matrix4 transposeMatrix(const Matrix4 v);
	float det(void) const;

	//operacje na macierzach
	void setTranslationPart(const Vector &translation);
	void setScalePart(const Vector &scale);
	void setScalePartUniform(const float scaleFactor);
	void setRotationAxis(const double angle, const Vector& axis);
	void setRotationX(const double angle);
	void setRotationY(const double angle);
	void setRotationZ(const double angle);
};


#endif //MATMA_MATRIX4_H
