#pragma once

#include <vector>
#include "vector.h"

using namespace std;

template <typename T, typename U>
class Map
{
private:
	vector<T> keys;
	vector<U> values;
	int codeError;

public:
	Map();
	~Map();

	T &operator[](size_t pos);

	void add(size_t pos, T key, U value);
	void push_back(T key, U value);

	void print();
};

#include "map.tpp"