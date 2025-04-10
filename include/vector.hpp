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
	Vector(size_t n);
	Vector(size_t n, T value);
	Vector(const Vector &other);

	~Vector();

	void print() const;
};

// class Vector
// {
// private:
// 	T *data;
// 	int size;
// 	int codeError;

// public:
// 	Vector();
// 	// Vector(int n);
// 	// Vector(int n, int value);

// 	// Vector(const Vector &other);

// 	~Vector();

// 	// Vector &operator++();
// 	// Vector operator++(int);
// 	// Vector &operator--();
// 	// Vector operator--(int);

// 	// bool operator!() const;

// 	// Vector operator~();

// 	// Vector &operator-();

// 	// Vector &operator=(const Vector &other);

// 	// Vector operator+=(const Vector &other);
// 	// Vector operator-=(const Vector &other);
// 	// Vector operator*=(const int &other);
// 	// Vector operator/=(const int &other);
// 	// Vector operator%=(const int &other);
// 	// Vector operator|=(const Vector &other);
// 	// Vector operator^=(const Vector &other);
// 	// Vector operator&=(const Vector &other);

// 	// Vector operator+(const Vector &other);
// 	// Vector operator-(const Vector &other);
// 	// Vector operator*(const int &other);
// 	// Vector operator/(const int &other);
// 	// Vector operator%(const int &other);

// 	// Vector operator|(const Vector &other);
// 	// Vector operator^(const Vector &other);
// 	// Vector operator&(const Vector &other);

// 	// void print() const;
// };

#include "vector.tpp"