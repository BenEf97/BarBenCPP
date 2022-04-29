#define _CRT_SECURE_NO_WARNINGS
#include "ManagementTrips.h"
#include "Trip.h"
#include <iostream>
using namespace std;

void deleteTrips(ManagementTrips* mts);
void AddTrip(ManagementTrips* mts);

void main() {
	ManagementTrips mts;
	int option;
	do
	{
		cout << "\nPlease Select an option: \n1.Print Trips\n2.Delete Trips\n3.Add Trip\n4.Exit" << endl;
			cin >> option;
		switch (option)
		{
		case 1:
			cout <<"****Trips in the database******\n"<< mts;
			break;
		case 2:
			deleteTrips(&mts);
			break;
		case 3:
			AddTrip(&mts);
			break;
		case 4:
			cout << "bye bye!" << endl;
			break;
		default:
			cout << "invaild option" << endl;
			break;
		}
	} while (option != 4);
}

//delets trip from mts 
void deleteTrips(ManagementTrips* mts)
{
	int d, m, y;
	cout <<"please enter a date:\n"<<"Please enter day: ";
	cin >> d;
	cout << "Please enter month: ";
	cin >> m;
	cout << "Please enter year: ";
	cin >> y;
	Date newD(d, m, y);
	Trip t(newD);
	*mts -= t;
	cout << "All trips deleted in " << newD << endl;
}

//adds trips to mts
void AddTrip(ManagementTrips* mts)
{
	//init arguments
	int d, m, y;
	char dest[50];

	cout << "Please enter trip details:\nEnter Destination: ";
	cin.ignore();
	cin.getline(dest, 49, '\n');
	cout << "Please enter day: ";
	cin >> d;
	cout << "Please enter month: ";
	cin >> m;
	cout << "Please enter year: ";
	cin >> y;
	Date newD(d, m, y);
	Trip t(dest, newD);
	*mts += t;
	
}