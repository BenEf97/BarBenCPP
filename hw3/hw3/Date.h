//#pragma once
#ifndef __DATE_H
#define __DATE_H

class Date
{
private:
	int day, month, year;
public:
	Date(int d, int m, int y);
	Date(); //changed 
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void PrintDate() const;
};

#endif // !__DATE_H