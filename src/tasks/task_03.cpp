#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "class/matrix.h"

using namespace std;

void task_03()
{
	Matrix<char> matrixChar(3, 3);

	matrixChar(0, 0) = 'a';
	matrixChar(0, 1) = 'b';
	matrixChar(0, 2) = 'c';
	matrixChar(1, 0) = 'd';
	matrixChar(1, 1) = 'e';
	matrixChar(1, 2) = 'f';
	matrixChar(2, 0) = 'g';
	matrixChar(2, 1) = 'h';
	matrixChar(2, 2) = 'i';

	matrixChar.print();

	newLine();

	Matrix<int> matrix(3, 3);

	matrix(0, 0) = 1;
	matrix(0, 1) = 2;
	matrix(0, 2) = 3;
	matrix(1, 0) = 4;
	matrix(1, 1) = 5;
	matrix(1, 2) = 6;
	matrix(2, 0) = 7;
	matrix(2, 1) = 8;
	matrix(2, 2) = 9;

	matrix.print();

	newLine();

	Matrix<int> E(5);
	E.print();

	newLine();

	Matrix<int> m1(3, 3, 1);
	m1.print();

	newLine();

	Matrix<int> m2(m1);
	m2.print();

	cout << "Objects: " << Matrix<int>::getTotalCount() << endl;
}
