#pragma once

#include "vector.h"

using namespace std;

template <typename T>
class Matrix
{
public:
	Vector<T> *data;
	size_t rows;
	size_t columns;
};