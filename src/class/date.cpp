#include "date.h"

using namespace std;

Month months[12] = {{1, "January"}, {2, "February"}, {3, "March"}, {4, "April"}, {5, "May"}, {6, "June"}, {7, "July"}, {8, "August"}, {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}};

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y)
{
	if (isValidDay(d) && isValidMonth(m) && isValidYear(y))
	{
		day = d;
		month = m;
		year = y;
	}
	else
	{
		day = 1;
		month = 1;
		year = 2000;
	}
}

bool Date::isLeapYear(int y) { return y % 4 == 0; }

bool Date::isValidDay(int d)
{
	{
		if (d < 1 || d > 31)
			return false;

		if (month == 2)
		{
			if (isLeapYear(year))
				return d <= 29;
			else
				return d <= 28;
		}

		if (month == 4 || month == 6 || month == 9 || month == 11)
			return d <= 30;

		return true;
	}
}
bool Date::isValidMonth(int m) { return m >= 1 && m <= 12; }
bool Date::isValidYear(int y) { return y >= 1; }

void Date::setDay(int d)
{
	if (!isValidDay(d))
	{
		cout << "Not correct day!" << endl;
		return;
	}
	day = d;
}

void Date::setMonth(int m)
{
	if (!isValidMonth(m))
	{
		cout << "Not correct month!" << endl;
		return;
	}
	month = m;
}

void Date::setYear(int y)
{
	if (!isValidYear(y))
	{
		cout << "Not correct year!" << endl;
		return;
	}
	year = y;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::printFullDate() const { cout << day << " " << months[month - 1].name << " " << year << " year" << endl; }
void Date::printShortDate() const { cout << setw(2) << setfill('0') << day << "." << setw(2) << setfill('0') << month << "." << year << endl; }
