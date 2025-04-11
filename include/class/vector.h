#pragma once

#include <iostream>

#include "console.h"
#include "taskManager.h"

template <typename T>
class Vector
{
private:
	T *data;
	size_t size;
	int codeError;

public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, T value);

	Vector(const Vector &other);

	~Vector();

	Vector operator[](size_t index) const;

	Vector &operator++();
	Vector operator++(int);
	Vector &operator--();
	Vector operator--(int);

	bool operator!() const;

	Vector operator~();

	Vector &operator-();

	Vector &operator=(const Vector &other);

	Vector operator+=(const Vector &other);
	Vector operator-=(const Vector &other);
	Vector operator*=(const int &other);
	Vector operator/=(const int &other);
	Vector operator%=(const int &other);
	Vector operator|=(const Vector &other);
	Vector operator^=(const Vector &other);
	Vector operator&=(const Vector &other);

	Vector operator+(const Vector &other);
	Vector operator-(const Vector &other);
	Vector operator*(const int &other);
	Vector operator/(const int &other);
	Vector operator%(const int &other);

	Vector operator|(const Vector &other);
	Vector operator^(const Vector &other);
	Vector operator&(const Vector &other);

	Vector &operator<<(const int &other);
	Vector &operator>>(const int &other);

	T &operator[](size_t index);

	void print() const;
};

#include "vector.tpp"