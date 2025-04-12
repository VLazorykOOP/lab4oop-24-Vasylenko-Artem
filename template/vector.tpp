#include "class/vector.h"

using namespace std;

VectorError vectorError[3] = {{0, "No error"}, {1, "Vector sizes are not equal"}, {2, "Not enough memory"}};

template <typename T>
Vector<T>::Vector() : size(1) { data = new T[size]; }

template <typename T>
Vector<T>::Vector(size_t n) : size(n) { data = new T[size]; }

template <typename T>
Vector<T>::Vector(size_t n, T value) : size(n)
{
	data = new T[size];
	for (size_t i = 0; i < n; i++)
		data[i] = value;
}

template <typename T>
Vector<T>::Vector(const Vector &other) : size(other.size)
{
	data = new T[size];
	for (size_t i = 0; i < other.size; i++)
		data[i] = other.data[i];
}

template <typename T>
Vector<T>::~Vector() { delete[] data; }

template <typename T>
Vector<T> &Vector<T>::operator++()
{
	for (size_t i = 0; i < size; i++)
		++data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator++(int)
{
	Vector temp(*this);
	++(*this);
	return temp;
}

template <typename T>
Vector<T> &Vector<T>::operator--()
{
	for (size_t i = 0; i < size; ++i)
		--data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator--(int)
{
	Vector temp(*this);
	--(*this);
	return temp;
}

template <typename T>
bool Vector<T>::operator!() const
{
	if (size == 0)
		return true;

	for (size_t i = 0; i < size; i++)
		if (data[i] != 0)
			return false;

	return true;
}

template <typename T>
Vector<T> Vector<T>::operator~()
{
	for (size_t i = 0; i < size; i++)
		data[i] = ~data[i];
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator-()
{
	for (size_t i = 0; i < size; i++)
		data[i] = -data[i];
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other)
{
	if (this != &other)
	{
		delete[] data;
		size = other.size;
		data = new (nothrow) int[size];
		if (!data)
		{
			codeError = 2;
			return *this;
		}
		for (size_t i = 0; i < size; i++)
			data[i] = other.data[i];
	}
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] += other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator-=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] -= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator*=(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] *= other;
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator/=(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] /= other;
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator%=(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] %= other;
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator|=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] |= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator^=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] ^= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator&=(const Vector &other)
{
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return *this;
	}

	for (size_t i = 0; i < size; i++)
		data[i] &= other.data[i];
	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] + other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] - other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator*(const int &other)
{
	Vector temp(size);
	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] * other;
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator/(const int &other)
{
	Vector temp(size);
	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] / other;
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator%(const int &other)
{
	Vector temp(size);
	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] % other;
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator|(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] | other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator^(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] ^ other.data[i];
	return temp;
}

template <typename T>
Vector<T> Vector<T>::operator&(const Vector &other)
{
	Vector temp(size);
	if (size != other.size)
	{
		codeError = 1;
		cout << "Vector sizes are not equal" << endl;
		return temp;
	}

	for (size_t i = 0; i < size; i++)
		temp.data[i] = data[i] & other.data[i];
	return temp;
}

template <typename T>
Vector<T> &Vector<T>::operator<<(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] <<= other;
	return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator>>(const int &other)
{
	for (size_t i = 0; i < size; i++)
		data[i] >>= other;
	return *this;
}

template <typename T>
ostream &operator<<(ostream &os, const Vector<T> &v)
{
	for (size_t i = 0; i < v.size; i++)
		os << v.data[i] << " ";
	return os;
}

template <typename T>
istream &operator>>(istream &is, Vector<T> &v)
{
	for (size_t i = 0; i < v.size; i++)
		is >> v.data[i];
	return is;
}

template <typename T>
bool Vector<T>::operator==(const Vector &other) const
{
	if (size != other.size)
		return false;
	for (size_t i = 0; i < size; i++)
		if (data[i] != other.data[i])
			return false;
	return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector &other) const { return !(*this == other); }

template <typename T>
T &Vector<T>::operator[](size_t index)
{
	if (index >= size)
	{
		codeError = 3;
		static T dummy{};
		return dummy;
	}
	return data[index];
}

template <typename T>
void *Vector<T>::operator new[](size_t size)
{
	// this->size = size;
	// data = new T[size];
}

template <typename T>
void Vector<T>::operator delete[](void *ptr)
{
	// delete[] ptr;
}

// template <typename T>
// bool Vector<T>::operator>(const Vector &other) const
// {
// 	if (size != other.size)
// 		return false;
// 	for (size_t i = 0; i < size; i++)
// 		if (data[i] <= other.data[i])
// 			return false;
// 	return true;
// }

// template <typename T>
// bool Vector<T>::operator<(const Vector &other) const { return !(*this > other); }

template <typename T>
bool Vector<T>::operator<(const Vector &other) const
{
	size_t minSize = min(size, other.size);
	for (size_t i = 0; i < minSize; ++i)
	{
		if (data[i] < other.data[i])
			return true;
		if (data[i] > other.data[i])
			return false;
	}
	return size < other.size;
}

template <typename T>
bool Vector<T>::operator>(const Vector &other) const { return other < *this; }

template <typename T>
bool Vector<T>::operator<=(const Vector &other) const { return !(*this > other); }

template <typename T>
bool Vector<T>::operator>=(const Vector &other) const { return !(*this < other); }

template <typename T>
size_t Vector<T>::getSize() const { return size; }

template <typename T>
void Vector<T>::empty()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

template <typename T>
void Vector<T>::print() const
{
	for (size_t i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}
