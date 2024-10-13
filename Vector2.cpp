#include "Vector2.h"

Vector2::Vector2(float _x, float _y) {
	x = _x;
	y = _y;
}

float Vector2::GetX() {
	return x;
}

float Vector2::GetY() {
	return y;
}

void Vector2::SetX(float _x) {
	x = _x;
}

void Vector2::SetY(float _y) {
	y = _y;
}

float Vector2::Magnitude() {
	return sqrt(x * x + y * y);
}
Vector2 Vector2::Normalize() {
	return (Magnitude() == 0 ? Vector2(0, 0) : *this / Magnitude());
}
std::string Vector2::toString() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2 Vector2::operator+(const Vector2& _other) {
	return Vector2(
		this->x + _other.x,
		this->y + _other.y
	);
}
Vector2 Vector2::operator-(const Vector2& _other) {
	return Vector2(
		this->x - _other.x,
		this->y - _other.y
	);
}
Vector2 Vector2::operator*(float _other) {
	return Vector2(
		this->x * _other,
		this->y * _other
	);
}
Vector2 Vector2::operator/(float _other) {
	return Vector2(
		this->x / _other,
		this->y / _other
	);
}
Vector2 Vector2::operator+=(const Vector2 & _other) {
	return Vector2(
		this->x + _other.x,
		this->y + _other.y
	);
}
Vector2 Vector2::operator-=(const Vector2 & _other) {
	return Vector2(
		this->x - _other.x,
		this->y - _other.y
	);
}
Vector2 Vector2::operator*=(float _other) {
	return Vector2(
		this->x * _other,
		this->y * _other
	);
}
Vector2 Vector2::operator/=(float _other) {
	return Vector2(
		this->x / _other,
		this->y / _other
	);

}	