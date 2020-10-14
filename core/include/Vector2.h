#pragma once

#include <math.h>

class Vector2
{

public:

	Vector2() : X(0), Y(0) { }
	Vector2(float x, float y) : X(x), Y(y) { }

	static Vector2 Zero;
	static Vector2 One;
	static Vector2 Right;
	static Vector2 Up;

	Vector2 operator+(const Vector2& v) const { return Vector2(X + v.X, Y + v.Y); }
	Vector2 operator-(const Vector2& v) const { return Vector2(X - v.X, Y - v.Y); }
	Vector2 operator-() const { return Vector2(-X, -Y); }
	Vector2 operator*(float t) const { return Vector2(t * X, t * Y); }
	Vector2 operator/(float t) const { return Vector2(X / t, Y / t); }

	Vector2& operator+=(const Vector2& v) { X += v.X; Y += v.Y; return *this; }
	Vector2& operator-=(const Vector2& v) { X -= v.X; Y -= v.Y; return *this; }
	Vector2& operator*=(float t) { X *= t; Y *= t; return *this; }
	Vector2& operator/=(float t) { X /= t; Y /= t; return *this; }

	bool operator==(const Vector2& v) { return X == v.X && Y == v.Y; }
	bool operator!=(const Vector2& v) { return X != v.X || Y != v.Y; }

	float Length() const { return sqrtf(X * X + Y * Y); }
	float LengthSquared() const { return X * X + Y * Y; }

	Vector2 Normalize() const
	{
		float length = Length();
		return length != 0 ? (*this) / length : *this;
	}

public:
	float X;
	float Y;
};


