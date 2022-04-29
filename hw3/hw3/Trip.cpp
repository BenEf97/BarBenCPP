#include "Trip.h"
#include <iostream>
#include <cstring>
using namespace std;



//init counter
 int Trip::counter = MIN_TRIP_COUNT;

//check if date is correct
Trip::Trip()
{
	NumOfTrip = counter;
	Destination = NULL;
	date;
}


// constructor
Trip::Trip(const char * dest, Date d)
{
	//setNoT(Num);
	counter++;
	NumOfTrip = counter;
	Destination = NULL;
	setDes(dest);
	setDate(d);
}

//Empty constructor
Trip::Trip(Date d)
{
	
	NumOfTrip = 0;
	Destination = NULL;
	setDate(d);
}

//Copy constructor
Trip::Trip(const Trip & t)
{
	counter++;
	NumOfTrip = counter;
	Destination = NULL;
	setDes(t.Destination);
	date = t.date;
}

//gets the number of the trip.
int Trip::getNoT() const
{
	return NumOfTrip;
}

//gets the destination, check if it works.
const char * Trip::getDes() const
{
	return Destination;
}

//gets the date.
Date Trip::getDate() const
{
	return date;
}


//setting the destinaion, checks if it's correct, also check for duplicating of the code.
void Trip::setDes(const char * dest)
{
	delete[] Destination;

	//Valid input check
	for (int idx = 0; idx < strlen(dest); idx++)
	{
		//Checking if the input doesn't contain letters.
		if ((dest[idx]<'A' || dest[idx]>'z') && dest[idx] != ' ')
		{
			//Default destination is Alabama.
			Destination = new char[9];
			strcpy_s(Destination, 9, "Alabama");
			return;
		}
	}
	//if the input is valid, will allocate memory
	Destination = new char[strlen(dest) + 1];
	strcpy_s(Destination, strlen(dest) + 1, dest);
}


//setting the date
void Trip::setDate(Date d)
{
	date = d;
}


//deletes the trip
Trip::~Trip()
{
	//counter--;
	delete[] Destination;
}


//= operator, gets and object reference and initilize all the fields
const Trip& Trip::operator=(const Trip &t)
{
	if (this != &t) //is there an != operator?
	{
		NumOfTrip = t.NumOfTrip;
		date = t.date;
		Destination = NULL;
		delete[] Destination;
		//if(&Destination!=NULL)
		Destination = new char[strlen(t.Destination) + 1];
		strcpy_s(Destination, strlen(t.Destination) + 1, t.Destination);
	}
	return *this;
}
//Print Trip '<<' operator
ostream & operator<<(ostream & os, const Trip & t)
{
	os << "Number of Trip: " << t.NumOfTrip << "\nDestination: " << t.Destination <<"\n"<<t.date<< endl;
	return os;
}
