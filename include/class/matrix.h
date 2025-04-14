#pragma once

#include "vector.h"

using namespace std;

template <typename T>
class Matrix
{
private:
	Vector<T> *data;
	size_t rows;
	size_t columns;

public:
	Matrix();
	Matrix(size_t size); // E
	Matrix(size_t rows, size_t columns);
	~Matrix();
	T &operator()(size_t row, size_t column);
	const T &operator()(size_t row, size_t column) const;

	void print() const;
};

#include "matrix.tpp"