#include "Trip.h"
#include <iostream>
#include <cstring>
using namespace std;

/*Notes:
maybe need to do '=' operator.
need to do print trip*/

//check if date is correct
Trip::Trip()
{
	NumOfTrip = 0;
	Destination = NULL;
	date;
}


//check if date is correct
Trip::Trip(int Num, const char * dest, Date d)
{
	setNoT(Num);
	Destination = NULL;
	setDes(dest);
	setDate(d);
}

//Copy constructor, check if it works
Trip::Trip(const Trip & t)
{
	NumOfTrip = t.NumOfTrip;
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

//setting the number of the trip
void Trip::setNoT(int NoT)
{
	if (NoT>0)
		NumOfTrip = NoT;
	else NumOfTrip = 1000;
}

//setting the destinaion, checks if it's correct, also check for duplicating of the code.
void Trip::setDes(const char * dest)
{
	delete[] Destination;

	//Valid input check
	for (int idx = 0; idx < strlen(dest); idx++)
	{
		//Checking if the input doesn't contain letters.
		if ((dest[idx]<'A' || dest[idx]>'z')&&dest[idx]!=' ')
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

//Prints trip details
void Trip::PrintTrip() const
{
	cout << "Number of Trip: " << NumOfTrip << "\nDestination: " << Destination << endl;
	date.PrintDate();
}

//deletes the trip
Trip::~Trip()
{
	delete[] Destination;
}


//= operator, gets and object reference and initilize all the fields
 const Trip& Trip::operator=(const Trip &t)
{
	if (this!= &t)
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