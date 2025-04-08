#include "matrix.h"

using namespace std;

Matrix::Matrix() : rows(3), cols(3), error_code(0)
{
	allocateAndInitialize(3, 3, 0);
	object_count++;
}

Matrix::Matrix(int n) : rows(n), cols(n), error_code(0)
{
	allocateAndInitialize(n, n, 0);
	object_count++;
}

Matrix::Matrix(int n, int m, int value) : rows(n), cols(m), error_code(0)
{
	allocateAndInitialize(n, m, value);
	object_count++;
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), error_code(other.error_code)
{
	allocateAndCopy(other);
	object_count++;
}

Matrix &Matrix::operator=(const Matrix &other)
{
	if (this != &other)
	{
		delete[] data;
		rows = other.rows;
		cols = other.cols;
		error_code = other.error_code;
		allocateAndCopy(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	cout << "Destructor called" << endl;
	delete[] data;
	object_count--;
}

void Matrix::setElement(int i, int j, int value)
{
	if (isValidIndex(i, j))
		data[i * cols + j] = value;
	else
		error_code = 1;
}

int Matrix::getElement(int i, int j) const
{
	if (isValidIndex(i, j))
		return data[i * cols + j];

	return 0;
}

int Matrix::object_count = 0;

void Matrix::allocateAndInitialize(int n, int m, int value)
{
	data = new (nothrow) int[n * m];
	if (!data)
	{
		error_code = 2;
		return;
	}
	for (int i = 0; i < n * m; i++)
		data[i] = value;
}

void Matrix::allocateAndCopy(const Matrix &other)
{
	data = new (nothrow) int[rows * cols];
	if (!data)
	{
		error_code = 2;
		return;
	}
	for (int i = 0; i < rows * cols; i++)
		data[i] = other.data[i];
}

bool Matrix::isValidIndex(int i, int j) const { return i >= 0 && i < rows && j >= 0 && j < cols; }

void Matrix::print() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << getElement(i, j) << " ";
		cout << endl;
	}
}

Matrix Matrix::operator+(const Matrix &other) const
{
	if (rows != other.rows || cols != other.cols)
		return Matrix();

	Matrix result(rows, cols, 0);
	for (int i = 0; i < rows * cols; i++)
		result.data[i] = data[i] + other.data[i];

	return result;
}

Matrix Matrix::operator-(const Matrix &other) const
{
	if (rows != other.rows || cols != other.cols)
		return Matrix();

	Matrix result(rows, cols, 0);
	for (int i = 0; i < rows * cols; i++)
		result.data[i] = data[i] - other.data[i];

	return result;
}

Matrix Matrix::operator*(const Matrix &other) const
{
	if (cols != other.rows)
		return Matrix();

	Matrix result(rows, other.cols, 0);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < other.cols; j++)
			for (int k = 0; k < cols; k++)
				result.data[i * other.cols + j] += data[i * cols + k] * other.data[k * other.cols + j];

	return result;
}

bool Matrix::operator==(const Matrix &other) const
{
	if (rows != other.rows || cols != other.cols)
		return false;

	for (int i = 0; i < rows * cols; i++)
		if (data[i] != other.data[i])
			return false;

	return true;
}

bool Matrix::operator<(const Matrix &other) const
{
	if (rows > other.rows || cols > other.cols)
		return false;

	for (int i = 0; i < rows * cols; i++)
		if (data[i] > other.data[i])
			return false;

	return true;
}

bool Matrix::operator>(const Matrix &other) const
{
	if (rows < other.rows || cols < other.cols)
		return false;

	for (int i = 0; i < rows * cols; i++)
		if (data[i] < other.data[i])
			return false;

	return true;
}

bool Matrix::operator!=(const Matrix &other) const { return !(*this == other); }