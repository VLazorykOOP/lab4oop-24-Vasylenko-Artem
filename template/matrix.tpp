#include "class/matrix.h"

template <typename T>
Matrix<T>::Matrix() : rows(0), columns(0), data(nullptr) { totalCount++; }

template <typename T>
Matrix<T>::Matrix(size_t size) : rows(size), columns(size)
{
	data = new Vector<T>[size];
	for (size_t i = 0; i < size; i++)
		data[i] = Vector<T>(size);

	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			i == j ? data[i][j] = 1 : data[i][j] = 0;

	totalCount++;
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns) : rows(rows), columns(columns)
{
	data = new Vector<T>[rows];
	totalCount++;
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns, T value) : rows(rows), columns(columns)
{
	data = new Vector<T>[rows];
	for (size_t i = 0; i < rows; i++)
		data[i] = Vector<T>(columns, value);
	totalCount++;
}

template <typename T>
Matrix<T>::Matrix(const Matrix &other) : rows(other.rows), columns(other.columns)
{
	data = new Vector<T>[rows];
	for (size_t i = 0; i < rows; i++)
		data[i] = other.data[i];
	totalCount++;
}

int MatrixBase::totalCount = 0;

template <typename T>
Matrix<T>::~Matrix()
{
	delete[] data;
	totalCount--;
}

template <typename T>
Matrix<T> &Matrix<T>::operator++()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j]++;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator++(int)
{
	Matrix temp(*this);
	++*this;
	return temp;
}

template <typename T>
Matrix<T> &Matrix<T>::operator--()
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < columns; j++)
			data[i][j]--;
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator--(int)
{
	Matrix temp(*this);
	--*this;
	return temp;
}

template <typename T>
T &Matrix<T>::operator()(size_t row, size_t column) { return data[row][column]; }

template <typename T>
const T &Matrix<T>::operator()(size_t row, size_t column) const { return data[row][column]; }

int MatrixBase::getTotalCount() { return totalCount; }

template <typename T>
void Matrix<T>::print() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}
}