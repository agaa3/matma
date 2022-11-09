#include "Vector.h"


Vector::Vector() {
	//ctor
}

Vector::~Vector() {
	//dtor
}

Vector::Vector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(const Vector &v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;

}
Vector Vector::operator+(const Vector &w) const {
	Vector res(0, 0, 0);
	res.x = w.x + this->x;
	res.y = w.y + this->y;
	res.z = w.z + this->z;

	return res;
}

Vector Vector::operator-(const Vector &w) const {
	Vector res(0, 0, 0);
	res.x = this->x - w.x;
	res.y = this->y - w.y;
	res.z = this->z - w.z;

	return res;
}

Vector Vector::operator*(const float &k) const {
	Vector res(0, 0, 0);
	res.x = this->x * k;
	res.y = this->y * k;
	res.z = this->z * k;

	return res;
}

Vector Vector::operator/(const float &k) const {
	if (k == 0)
		throw std::invalid_argument("Dzielenie przez 0");

	Vector res(0, 0, 0);
	res.x = this->x / k;
	res.y = this->y / k;
	res.z = this->z / k;

	return res;
}

float Vector::length() const {
	return (float) sqrt(pow(this->x, 2) +
	                    pow(this->y, 2) +
	                    pow(this->z, 2));
}

Vector Vector::normalize() const {
	float n = this->length();
	if (n == 0)
		throw std::invalid_argument("Dzielenie przez 0");
	return this->operator/(n);
}

Vector Vector::dot(const Vector v) const {
	Vector result;
	result.x = this->x * v.x;
	result.y = this->y * v.y;
	result.z = this->z * v.z;
	return result;
}

float Vector::dotProduct(const Vector v) {
	Vector result;
	result.x = this->x * v.x;
	result.y = this->y * v.y;
	result.z = this->z * v.z;
	return result.x + result.y + result.z;
}

Vector Vector::cross(const Vector v) {
	return Vector(this->y * v.z - this->z * v.y,
	              this->z * v.x - this->x * v.z,
	              this->x * v.y - this->y * v.x);
}

std::ostream& operator<<(std::ostream& stream, const Vector& v) {
	stream << "[ " << v.x << ", " << v.y << ", " << v.z << "]";
	return stream;
}
