#include "Date.h"
#include <iostream>
using namespace std;

/*Notes: check if the constructors are done right.*/

//Work on date, all the functions.
Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
	setDay(d);
	setMonth(m);
	setYear(y);
}


//Needed to do empty constructor, check if it's right.
Date::Date()
{
	Date(0, 0, 0);
}

//returns the day
unsigned int Date::getDay() const
{
	return day;
}

//returns the month
unsigned int Date::getMonth() const
{
	return month;
}

//returns the year
unsigned int Date::getYear() const
{
	return year;
}


//setting the day, checks for valid input.
void Date::setDay(unsigned int d)
{
	//Checks for valid input, assuming month has 30 days. If the input is invalid, will set day=0.
	if (d < 1 || d>30)
		day = 0;
	else
		day = d;
}

//setting the month, checks for valid input.
void Date::setMonth(unsigned int m)
{
	//Checks for valid inout, if there is invalid input will be set month=0
	if (m < 1 || m>12)
		month = 0;
	else
		month = m;
}


//setting the year.
void Date::setYear(unsigned int y)
{
	year = y;
}


//Prints the date in dd/mm/yy format.
void Date::PrintDate() const
{
	cout << "The Date: "<<day<<"/"<<month<<"/"<<year<<"\n"<<endl;
}
