#include "class/map.h"

using namespace std;

template <class T, class U>
Map<T, U>::Map() : size(0)
{
	keys = Vector<T>(size);
	values = Vector<U>(size);
}

template <class T, class U>
Map<T, U>::~Map()
{
	// keys.~Vector();
	// values.~Vector();
}

// template <class T, class U>
// T &Map<T, U>::operator[](size_t pos)
// {
// 	// if (pos >= keys.size() ||)
// 	return keys[pos];
// }

// template <class T, class U>
// U &Map<T, U>::operator[](const T &key)
// {
// 	for (size_t i = 0; i < keys.getSize(); ++i)
// 	{
// 		if (keys[i] == key)
// 			return values[i];
// 	}

// 	codeError = 1;
// 	static U emptyValue{};
// 	return emptyValue;
// }

// template <class T, class U>
// void Map<T, U>::add(size_t pos, T key, U value)
// {
// 	keys[pos] = key;
// 	values[pos] = value;
// }

template <class T, class U>
void Map<T, U>::push_back(T key, U value)
{
	keys.push_back(key);
	values.push_back(value);
}

template <class T, class U>
void Map<T, U>::print()
{
	for (size_t i = 0; i < keys.getSize(); i++)
		cout << "Key: " << keys[i] << " - Value: " << values[i] << endl;
}
