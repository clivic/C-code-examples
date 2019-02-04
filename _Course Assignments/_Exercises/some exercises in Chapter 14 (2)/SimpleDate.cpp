//*************************************************************************************************
//this is the simpledate class implementation, it represents a date fomat of YYYY/MM/DD
//*************************************************************************************************
#include <iostream>
#include "SimpleDate.h"

using namespace std;

//private members:
//		int year;
//		int month;
//		int day;

SimpleDate::SimpleDate()
{
	year = 1127;
	month = 1;
	day = 1;
}

SimpleDate::SimpleDate(
	/* in */ int usingYear,
	/* in */ int usingMonth,
	/* in */ int usingDay)
{
	year = usingYear;
	month = usingMonth;
	day = usingDay;
}

int SimpleDate::GetDay() const
{
	return day;
}

int SimpleDate::GetMonth() const
{
	return month;
}

int SimpleDate::GetYear() const
{
	return year;
}

void SimpleDate::Set(
	/* in */ int usingYear,
	/* in */ int usingMonth,
	/* in */ int usingDay)
{
	year = usingYear;
	month = usingMonth;
	day = usingDay;
}

void SimpleDate::FormalWrite() const
{
	cout << year << '/';
	if (month < 10)
		cout << '0';
	cout << month << '/';
	if (day < 10)
		cout << '0';
	cout << day;
}

void SimpleDate::Write() const
{
	cout << year << '/' << month << '/' << day;
}