#include "Date.h"

//Work on date, all the functions.
Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
	day = setDay(d);
}

unsigned int Date::getDay() const
{
	return day;
}

unsigned int Date::getMonth() const
{
	return month;
}

unsigned int Date::getYear() const
{
	return year;
}

void Date::setDay(unsigned int d)
{
	//Checks for valid input, assuming month has 30 days. If the input is invalid, will set day=0.
	if (d < 1 || d>30)
		day = 0;
	else
		day = d;
}

void Date::setMonth(unsigned int m)
{
	//Checks for valid inout, if there is invalid input will be set month=0
	if (m < 1 || m>12)
		month = 0;
	else
		month = m;
}

void Date::setYear(unsigned int y)
{
	year = y;
}
