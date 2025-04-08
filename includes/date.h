#pragma once

#include <iostream>
#include <iomanip>

#include "console.h"
#include "taskManager.h"

using namespace std;

typedef struct Month
{
	short number;
	string name;
} Month;

class Date
{
private:
	int day;
	int month;
	int year;

	bool isLeapYear(int y);

	bool isValidDay(int d);
	bool isValidMonth(int m);
	bool isValidYear(int y);

public:
	Date();
	Date(int d, int m, int y);

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void printFullDate() const;
	void printShortDate() const;
};