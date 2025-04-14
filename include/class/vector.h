#pragma once

#include <iostream>

#include "console.h"
#include "taskManager.h"

using namespace std;

typedef struct
{
	int codeError;
	std::string message;
} VectorError;

template <typename T>
class Vector
{
private:
	T *data;
	size_t size;
	int codeError;
	static int countObject;

public:
	Vector();
	Vector(size_t n);
	Vector(size_t n, T value);

	Vector(const Vector &other);

	~Vector();

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

	friend ostream &operator<<(ostream &os, const Vector<T> &v);
	friend istream &operator>>(istream &is, Vector<T> &v);

	bool operator==(const Vector &other) const;
	bool operator!=(const Vector &other) const;

	T &operator[](size_t index);
	const T &operator[](size_t index) const;

	static void *operator new[](size_t size);
	static void operator delete[](void *ptr);

	bool operator>(const Vector &other) const;
	bool operator>=(const Vector &other) const;
	bool operator<(const Vector &other) const;
	bool operator<=(const Vector &other) const;

	void empty();
	size_t getSize() const;
	static int getCountObject();
	void print() const;
};

#include "vector.tpp"