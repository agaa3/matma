#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	//1
	Vector v1(1, 2, 3);
	Vector v2(3, 2, 1);

	cout << "1. Naprzemiennosc dodawania/odejmowania: " << endl
			<< v1 << endl
			<< v2 << endl
			<< "v1 + v2 - v2: \n" << v1 + v2 - v2  << endl;

	// 2
	cout << "\n2. Przemiennosc dodawnia, [v1 + v2] i [v2 + v1]: " << endl
			<< v1 + v2 << endl << v2 + v1 << endl;

	//2
	Vector v3(0, 3, 0);
	Vector v4(5, 5, 0);
	float dotProduct = v3.dotProduct(v4); //u*v=|u||v|cosalfa
	dotProduct /= (v3.length() * v4.length());
	float rad = acos(dotProduct); //radians
	float angle = rad * (180.0 / M_PI);

	cout << "\n3. Kat miedzy wektorami: " << endl
	     << v3 << endl
	     << v4 << endl
	     << "Kat: " << angle << " stopni" << endl;

	//3
	Vector v7(4, 5, 1);
	Vector v8(4, 1, 3);
	Vector cross = v7.cross(v8);
	cout << "\n4.Cross-product (wektor prostopadly): \n" << cross << endl;

	//4
	Vector norm = cross.normalize();
	cout << "\n5. Normalizacja \n" << norm << endl;

	return 0;
}