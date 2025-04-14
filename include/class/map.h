#pragma once

#include <vector>

using namespace std;

template <typename T, typename U>
class Map
{
private:
	vector<T> keys;
	vector<U> values;

public:
	Map();
	~Map();

	void add(size_t pos, T key, U value);
	void push_back(T key, U value);

	void print();
};

#include "map.tpp"