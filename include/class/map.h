#pragma once

// #include "class/vector.h"

template <typename T, typename U>
class Map
{
private:
	size_t size;
	// Vector<T> keys;
	// Vector<U> values;

public:
	Map();
	Map(size_t size);
	~Map();

	// void add(size_t position, );

	void print();
};

#include "map.tpp"