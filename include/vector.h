#pragma once

#include <iostream>

#include "console.h"
#include "taskManager.h"

class VectorInt
{
private:
	int *data;
	int size;
	int codeError;

public:
	VectorInt();
	VectorInt(int n);
	VectorInt(int n, int value);

	VectorInt(const VectorInt &other);

	~VectorInt();

	VectorInt &operator++();
	VectorInt operator++(int);

	VectorInt &operator--();
	VectorInt operator--(int);

	void print() const;
};
