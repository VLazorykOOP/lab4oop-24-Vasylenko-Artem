#pragma once

#include "vector.h"

using namespace std;

class MatrixBase
{
protected:
	static int totalCount;

public:
	static int getTotalCount();
};

template <typename T>
class Matrix : public MatrixBase
{
private:
	Vector<T> *data;
	size_t rows;
	size_t columns;
	static int codeError;

public:
	Matrix();
	Matrix(size_t size); // E
	Matrix(size_t rows, size_t columns);
	Matrix(size_t rows, size_t columns, T value);

	Matrix(const Matrix &other);

	~Matrix();

	T &operator()(size_t row, size_t column);
	const T &operator()(size_t row, size_t column) const;

	void print() const;
};

#include "matrix.tpp"