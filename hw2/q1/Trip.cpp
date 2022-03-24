#include "Trip.h"
#include <iostream>
#include <cstring>
using namespace std;

Trip::Trip()
{
}

Trip::Trip(unsigned int Num, const char * dest, Date d)
{
}

unsigned int Trip::getNoT() const
{
	return NumOfTrip;
}

char * Trip::getDes() const
{
	return Destination;
}

Date Trip::getDate() const
{
	return date;
}

void Trip::setNoT(unsigned int NoT)
{
	NumOfTrip = NoT;
}

void Trip::setDes(const char * dest)
{
	delete[] Destination;
	Destination = new char[strlen(dest) + 1];
	strcpy_s(Destination, strlen(dest) + 1, dest);
}

void Trip::setDate(Date d)
{
}
