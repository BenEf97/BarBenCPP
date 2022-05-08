#include "Date.h"
#include <iostream>
using namespace std;


//Work on date, all the functions.
Date::Date(int d, int m, int y)
{ 
	setDay(d);
	setMonth(m);
	setYear(y);
}


//Empty constructor
Date::Date()
{
	day = 1;
	month = 1;
	year = 2021;
}

//returns the day
int Date::getDay() const
{
	return day;
}

//returns the month
int Date::getMonth() const
{
	return month;
}

//returns the year
int Date::getYear() const
{
	return year;
}


//setting the day, checks for valid input.
void Date::setDay(int d) throw( char*)
{
	//Checks for valid input, assuming month has 31 days. If the input is invalid, will set day=0.
	if (d < 1 || d > 31)
	{
		throw "Invalid days input!";
		//day = 0;
	}
	else
		day = d;
}

//setting the month, checks for valid input.
void Date::setMonth(int m)  throw( char*)
{
	//Checks for valid inout, if there is invalid input will be set month=0
	if (m < 1 || m > 12)
		throw "Invalid months input!";
		//month = 0;
	else
		month = m;
}


//setting the year
void Date::setYear(int y)
{
	if (y > 0)
		year = y;
	else year = 2021;
}


//<< operator, prints the date details. replaces PrintDate method.
ostream& operator<<(ostream& os, const Date &d)
{
	os << "The Date: " << d.day << "/" << d.month << "/" << d.year << endl;
	return os;
}

//== operator, checks for equality. if true, returns true, else false.
bool Date::operator==(const Date d) const
{
	if (d.day == this->day && d.month == this->month &&d.year == this->year)
		return true;
	return false;
}
//checks if the date is later than this date
bool Date::operator>(const Date &d) const
{
	//Year and month might be the same, the day may not.
	if (d.year >= this->year && d.month >= this->month &&d.day > this->day)
		return true;

	return false;
}

//checks if the date is earlier 
bool Date::operator<(const Date & d) const
{
	//Year and month might be the same, the day may not.
	if (d.year <= this->year && d.month <= this->month &&d.day < this->day)
		return true;

	return false;
}