#pragma once

#include "vector.h"

using namespace std;

template <typename T, typename U>
class Map
{
private:
	Vector<T> keys;
	Vector<U> values;
	size_t size;
	int codeError;

public:
	Map();
	~Map();

	// T &operator[](size_t pos);
	// T &operator[](const T &key);
	U &operator[](size_t index);
	const U &operator[](size_t index) const;

	// void add(size_t pos, T key, U value);
	void push_back(T key, U value);

	void print();
};

#include "map.tpp"