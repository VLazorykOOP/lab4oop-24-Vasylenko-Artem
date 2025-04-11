#include "class/vector.h"

using namespace std;

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
const T &Vector<T>::operator[](size_t index) const
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
void Vector<T>::print() const
{
	for (size_t i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}
