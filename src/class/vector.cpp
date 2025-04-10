#include "vector.h"

using namespace std;

VectorInt::VectorInt() : size(1), codeError(0)
{
	data = new (nothrow) int[size];
	if (!data)
	{
		codeError = 2;
		return;
	}
}

VectorInt::VectorInt(int n) : size(n), codeError(0)
{
	data = new (nothrow) int[size];
	if (!data)
	{
		codeError = 2;
		return;
	}

	for (int i = 0; i < n; i++)
		data[i] = 0;
}

VectorInt::VectorInt(int n, int value) : size(n), codeError(0)
{
	data = new (nothrow) int[size];
	if (!data)
	{
		codeError = 2;
		return;
	}

	for (int i = 0; i < n; i++)
		data[i] = value;
}

VectorInt::VectorInt(const VectorInt &other) : size(other.size), codeError(0)
{
	data = new (nothrow) int[size];
	if (!data)
	{
		codeError = 2;
		return;
	}
	for (int i = 0; i < size; i++)
		data[i] = other.data[i];
}

VectorInt::~VectorInt() { delete[] data; }

void VectorInt::print() const
{
	for (int i = 0; i < size; ++i)
		cout << data[i] << " ";
	cout << endl;
}

VectorInt &VectorInt::operator++()
{
	for (int i = 0; i < size; i++)
		++data[i];
	return *this;
}

VectorInt VectorInt::operator++(int)
{
	VectorInt temp(*this);
	++(*this);
	return temp;
}

VectorInt &VectorInt::operator--()
{
	for (int i = 0; i < size; ++i)
		--data[i];
	return *this;
}

VectorInt VectorInt::operator--(int)
{
	VectorInt temp(*this);
	--(*this);
	return temp;
}
