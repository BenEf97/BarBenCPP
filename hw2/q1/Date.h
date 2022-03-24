//#pragma once
#ifndef __DATE_H
#define __DATE_H

class Date
{
private:
	unsigned int day, month, year;
public:
	Date(unsigned int d, unsigned int m, unsigned int y);
	Date();
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	void setDay(unsigned int d);
	void setMonth(unsigned int m);
	void setYear(unsigned int y);
	void PrintDate() const;
};

#endif // !__DATE_H