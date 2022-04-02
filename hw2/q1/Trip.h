//#pragma once
#ifndef  __TRIP_H
#define __TRIP_H

#include "Date.h"


class Trip
{
private:
	unsigned int NumOfTrip;
	char* Destination;
	Date date;

public:
	Trip();
	Trip(unsigned int Num, const char*dest, Date d);
	Trip(const Trip& t);
	unsigned int getNoT() const;
	const char* getDes() const;
	Date getDate() const;
	void setNoT(unsigned int NoT);
	void setDes(const char* dest);
	void setDate(Date d);
	void PrintTrip() const;
	~Trip();
	const Trip& operator=(const Trip &t);
};

#endif // !__TRIP_H
