//#pragma once
#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;



class Date
{
private:
	int day, month, year;
public:
	Date(int d, int m, int y);
	Date();
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	friend ostream& operator<<(ostream& os, const Date& d);
	bool operator == (const Date d) const;
	bool operator > (const Date& d) const;
	bool operator < (const Date& d) const;


};

#endif // !__DATE_H