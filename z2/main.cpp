#include <iostream>
#include "Vector.h"
#include "Matrix4.h"

int main() {
	// 1 Dodawanie
	float tmp[4][4] = {{1, 2, 3, 5},
	                 {3, 4.5, 9.8, 0.1},
	                 {1, 1, 1, 1},
	                 {0, 0, 0, 0}};
	Matrix4 m1 = Matrix4::makeIdentity();
	Matrix4 m2(tmp);
	Matrix4 m3(m2 + m1 + m2 / 5);

	float tA[16] = {1, 2, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1};
	Matrix4 A(tA);
	float tB[16] = {3, 4, 5, 2, 1, 2, 3, 1, 4, 4, 1, 2, 5, 4, 1, 2};
	Matrix4 B(tB);

	std::cout
		<< "m1:\n" << m1 << "m2:\n" << m2 << "Result: m1 + m2\n" << m1 + m2 << "\n\n"
		<< "m1:\n" << m1 << "m2:\n" << m2 << "Result: m1 - m2\n" << m1 - m2 << "\n\n"
		<< "m2:\n" << m2 << "Result: m2 * 2\n" << m2 * 2 << "\n\n"
		<< "m3:\n" << m3 << "Result: m3 / 4\n" << m3 / 4 << "\n\n"
		<< "A:\n" << A << "B:\n" << B
			<< "Result: A * B\n" << A * B << "\n"
			<< "Result: B * A\n" << B * A << "\n\n"
		<< "m2:\n" << m2 << "Transpose:\n" << Matrix4::transposeMatrix(m2) << "\n\n"
		<< "A:\n" << A << "det(A): " << A.det() << "\n"
		<< "B:\n" << B << "det(B): " << B.det() << "\n\n";

	Matrix4 m11 = Matrix4::makeIdentity();
	m11.setTranslationPart(Vector(1, 1.8, -9));

	Matrix4 m12 = Matrix4::makeIdentity();
	m12.setScalePart(Vector(-3, 2.1, 7));

	Matrix4 m13 = Matrix4::makeIdentity();
	m13.setScalePartUniform(3);

	Matrix4 m21 = Matrix4::makeIdentity();
	m21.setRotationX(90);

	Matrix4 m22 = Matrix4::makeIdentity();
	m22.setRotationY(90);

	Matrix4 m23 = Matrix4::makeIdentity();
	m23.setRotationZ(90);

	Matrix4 m33 = Matrix4::makeIdentity();
	Vector v = Vector(0.8f, 0.3f, -4.1f);
	m33.setRotationAxis(90, v);

	std::cout << "Operacje zrealizowane na macierzy jednostowej: " << m1
		<< "Translation Part:\n" << m11 << "\n"
		<< "Scale Part:\n" << m12 << "\n"
		<< "Scale Part Uniform:\n" << m13 << "\n"
		<< "Rotation X (90 stopni):\n" << m21 << "\n"
		<< "Rotation Y (90 stopni):\n" << m22 << "\n"
		<< "Rotation Z (90 stopni):\n" << m23 << "\n"
		<< "Rotation Axis (90 stopni):\n" << "axis: " << v << "\nResult: \n" << m33 << "\n\n";

	// obrót [1, 0, 0, 1] o oś Y o 90stp
	float obrotT[4][4] = {{1, 0, 0, 0},
	                  {0, 0, 0, 0},
	                  {0, 0, 0, 0},
	                  {1, 0, 0, 0}};

	Matrix4 obrot(obrotT);
	Matrix4 przeksztalcenie = Matrix4::makeIdentity();
	przeksztalcenie.setRotationY(90);

	std::cout
		<< "Obrot wektora [1, 0, 0, 1] aka:\n"
		<< obrot << "\nO 90 stopni wokol osi Y:\n"
		<< przeksztalcenie * obrot  << "\n";

	return 0;
}