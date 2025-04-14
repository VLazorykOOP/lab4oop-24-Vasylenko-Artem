#include "class/matrix.h"

template <typename T>
Matrix<T>::Matrix()
{
	data = nullptr;
	rows = 0;
	columns = 0;
}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns)
{
	data = new Vector<T>[rows];
	this->rows = rows;
	this->columns = columns;
}

template <typename T>
Matrix<T>::~Matrix()
{
	delete[] data;
}

template <typename T>
T &Matrix<T>::operator()(size_t row, size_t column)
{
	return data[row][column];
}

template <typename T>
const T &Matrix<T>::operator()(size_t row, size_t column) const
{
	return data[row][column];
}

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