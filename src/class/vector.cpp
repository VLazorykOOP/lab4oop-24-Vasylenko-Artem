#include "vector.h"

using namespace std;

Vector::Vector() : size(1), state(0)
{
	data = new (nothrow) int[1];
	if (!data)
		state = 1;
	else
		data[0] = 0;
	objectCount++;
}

Vector::Vector(int n) : size(n), state(0)
{
	data = new (nothrow) int[n];
	if (!data)
		state = 1;
	else
		fill(data, data + n, 0);
	objectCount++;
}

Vector::Vector(int n, int value) : size(n), state(0)
{
	data = new (nothrow) int[n];
	if (!data)
		state = 1;
	else
		fill(data, data + n, value);
	objectCount++;
}

Vector::Vector(const Vector &other) : size(other.size), state(other.state)
{
	data = new (nothrow) int[size];
	if (!data)
		state = 1;
	else
		copy(other.data, other.data + size, data);
	objectCount++;
}

Vector &Vector::operator=(const Vector &other)
{
	if (this != &other)
	{
		delete[] data;
		size = other.size;
		state = other.state;
		data = new (nothrow) int[size];
		if (!data)
			state = 1;
		else
			copy(other.data, other.data + size, data);
	}
	return *this;
}

Vector::~Vector()
{
	cout << "Vector destructor called" << endl;
	delete[] data;
	objectCount--;
}

void Vector::set(int index, int value)
{
	if (index >= size)
	{
		state = 1;
		throw out_of_range("Index out of bounds");
	}
	data[index] = value;
}

int Vector::get(int index) const
{
	if (index >= size)
		throw out_of_range("Index out of bounds");

	return data[index];
}

void Vector::print() const
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}

Vector Vector::operator+(const Vector &other) const
{
	if (size != other.size)
		throw invalid_argument("Vectors must be of the same size");

	Vector result(size);
	for (int i = 0; i < size; i++)
		result.data[i] = data[i] + other.data[i];

	return result;
}

Vector Vector::operator-(const Vector &other) const
{
	if (size != other.size)
		throw invalid_argument("Vectors must be of the same size");
	Vector result(size);
	for (int i = 0; i < size; i++)
		result.data[i] = data[i] - other.data[i];

	return result;
}

Vector Vector::operator*(short scalar) const
{
	Vector result(size);
	for (int i = 0; i < size; i++)
		result.data[i] = data[i] * scalar;

	return result;
}

bool Vector::operator==(const Vector &other) const
{
	if (size != other.size)
		return false;

	for (int i = 0; i < size; i++)
		if (data[i] != other.data[i])
			return false;

	return true;
}

bool Vector::operator!=(const Vector &other) const { return !(*this == other); }
bool Vector::operator<(const Vector &other) const { return size < other.size; }
bool Vector::operator>(const Vector &other) const { return size > other.size; }

int Vector::getState() const { return state; }
int Vector::getObjectCount() { return objectCount; }

int Vector::objectCount = 0;