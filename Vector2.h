#pragma once

#include <math.h>

#ifndef __VECTOR2__
#define __VECTOR2__

class Vector2 {
public:
	float x;
	float y;

	Vector2() : x(0), y(0) {}
	Vector2(float, float);

	float GetX();
	float GetY();
	void SetX(float);
	void SetY(float);

	float Magnitude();
	Vector2 Normalize();

	Vector2 operator+(const Vector2& _other);
	Vector2 operator-(const Vector2& _other);
	Vector2 operator*(float _other);
	Vector2 operator/(float _other);

	Vector2 operator+=(const Vector2& _other);
	Vector2 operator-=(const Vector2& _other);
	Vector2 operator*=(float _other);
	Vector2 operator/=(float _other);
};

#endif // !__VECTOR2__

