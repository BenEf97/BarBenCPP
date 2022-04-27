//#pragma once
#ifndef  __TRIP_H
#define __TRIP_H
#define MIN_TRIP_COUNT 0
#include "Date.h"


class Trip
{
private:
	int NumOfTrip;
	char* Destination;
	Date date;
public:
	static int counter; //should it be in private?
	Trip();
	Trip(int Num, const char*dest, Date d);
	Trip(const Trip& t);
	int getNoT() const;
	const char* getDes() const;
	Date getDate() const;
	//void setNoT(int NoT);
	void setDes(const char* dest);
	void setDate(Date d);
	//void PrintTrip() const;
	friend ostream& operator<<(ostream& os, const Trip& t);


	~Trip();
	const Trip& operator=(const Trip &t);
};

#endif // !__TRIP_H