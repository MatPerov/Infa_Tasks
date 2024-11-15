#pragma once
#include <cmath>
#include <iostream>

class Vector2f {
public:
	float x;
	float y;
	Vector2f(float x, float y) {
		this->x = x;
		this->y = y;
	}
};
std::ostream& operator<<(std::ostream& out, Vector2f a)
{
    return out << "(" << a.x << ", " << a.y << ")";
}

std::istream& operator>>(std::istream& in, Vector2f& a)
{
    return in >> a.x >> a.y;;
}

Vector2f operator+(Vector2f a, Vector2f b)
{
	Vector2f result = { a.x + b.x, a.y + b.y };
	return result;
}

Vector2f operator-(Vector2f a, Vector2f b)
{
	Vector2f result = { a.x - b.x, a.y - b.y };
	return result;
}

Vector2f operator-(Vector2f a)
{
	Vector2f result = { -a.x, -a.y};
	return result;
}

Vector2f operator+(Vector2f a)
{
	return a;
}

Vector2f operator*(Vector2f a, float b)
{
	Vector2f result = { a.x * b, a.y * b };
	return result;
}

float operator*(Vector2f a, Vector2f b)
{
	float result = a.x*b.x+a.y*b.y;
	return result;
}

Vector2f operator*(float b, Vector2f a)
{
	Vector2f result = { a.x * b, a.y * b };
	return result;
}

bool operator==(Vector2f a, Vector2f b) {
	if (a.x == b.x && a.y == b.y)
		return true;
	else
		return false;
}

bool operator!=(Vector2f a, Vector2f b) {
	if (a.x != b.x || a.y != b.y)
		return true;
	else
		return false;
}

Vector2f& operator+=(Vector2f& a, Vector2f b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

Vector2f& operator-=(Vector2f& a, Vector2f b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

Vector2f& operator*=(Vector2f& a, float b)
{
	a.x *= b;
	a.y *= b;
	return a;
}

Vector2f& operator/=(Vector2f& a, float b)
{
	a.x /= b;
	a.y /= b;
	return a;
}