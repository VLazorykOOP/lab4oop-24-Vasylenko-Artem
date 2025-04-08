#pragma once

#include <iostream>

#include "console.h"
#include "taskManager.h"

using namespace std;

class Matrix
{
private:
	int *data;
	int rows, cols;
	int error_code;
	static int object_count;

public:
	Matrix();

	Matrix(int n);
	Matrix(int n, int m, int value);

	Matrix(const Matrix &other);

	Matrix &operator=(const Matrix &other);

	~Matrix();

	void setElement(int i, int j, int value);

	int getElement(int i, int j) const;

	Matrix operator+(const Matrix &other) const;
	Matrix operator-(const Matrix &other) const;
	Matrix operator*(const Matrix &other) const;

	bool operator==(const Matrix &other) const;
	bool operator!=(const Matrix &other) const;
	bool operator<(const Matrix &other) const;
	bool operator>(const Matrix &other) const;

	void print() const;

	int getErrorCode() const { return error_code; }

	static int getObjectCount() { return object_count; }

private:
	void allocateAndInitialize(int n, int m, int value);
	void allocateAndCopy(const Matrix &other);
	bool isValidIndex(int i, int j) const;
};