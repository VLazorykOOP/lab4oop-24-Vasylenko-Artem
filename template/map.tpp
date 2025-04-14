#include "class/map.h"

using namespace std;

template <class T, class U>
Map<T, U>::Map() {}

template <class T, class U>
Map<T, U>::~Map()
{
	keys.clear();
	values.clear();
}

template <class T, class U>
void Map<T, U>::add(size_t pos, T key, U value)
{
	keys[pos] = key;
	values[pos] = value;
}

template <class T, class U>
void Map<T, U>::push_back(T key, U value)
{
	keys.push_back(key);
	values.push_back(value);
}

template <class T, class U>
void Map<T, U>::print()
{
	for (size_t i = 0; i < keys.size(); i++)
		cout << "Key: " << keys[i] << " - Value: " << values[i] << endl;
}
