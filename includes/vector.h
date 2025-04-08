#pragma once

#include <iostream>

#include "console.h"
#include "taskManager.h"

class Vector
{
private:
	int *data;
	int size;
	int state;
	static int objectCount;

public:
	Vector();
	Vector(int n);
	Vector(int n, int value);
	Vector(const Vector &other);

	~Vector();

	void set(int index, int value = 0);
	int get(int index) const;
	void print() const;

	Vector &operator=(const Vector &other);

	Vector operator+(const Vector &other) const;
	Vector operator-(const Vector &other) const;
	Vector operator*(short scalar) const;

	bool operator==(const Vector &other) const;
	bool operator!=(const Vector &other) const;
	bool operator<(const Vector &other) const;
	bool operator>(const Vector &other) const;

	int getState() const;
	static int getObjectCount();
};