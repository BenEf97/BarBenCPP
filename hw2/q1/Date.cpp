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
	year = 2000;
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
void Date::setDay(int d)
{
	//Checks for valid input, assuming month has 30 days. If the input is invalid, will set day=0.
	if (d < 1 || d > 30)
		day = 0;
	else
		day = d;
}

//setting the month, checks for valid input.
void Date::setMonth(int m)
{
	//Checks for valid inout, if there is invalid input will be set month=0
	if (m < 1 || m > 12)
		month = 0 ;
	else
		month = m;
}


//setting the year
void Date::setYear(int y)
{
	if (y>0)
		year = y;
	else year = 2000;
}


//Prints the date in dd/mm/yy format.
void Date::PrintDate() const
{
	cout << "The Date: "<<day<<"/"<<month<<"/"<<year<<"\n"<<endl;
}
