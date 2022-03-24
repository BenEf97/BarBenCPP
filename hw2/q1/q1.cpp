#include <iostream>
#include "Trip.h"

using namespace std;

bool IsEmpty(int size);
void Print(Trip* arr, int size);
void EditTrip(Trip* arr, int size);
Trip* AddTrip(Trip* arr, int size);


void main() {
	int option;
	Trip* arr = new Trip[0];
	int size = 0;
	do
	{
		cout << "Please Select an option: \n1.Print Trips\n2.Edit Trip\n3.Add Trip\n4.Exit" << endl;
			cin >> option;
		switch (option)
		{
		case 1:
			Print(arr, size);
			break;
		case 2:
			EditTrip(arr, size);
			break;
		case 3:
			arr = AddTrip(arr, size);
			size++;
			break;
		case 4:
			cout << "bye bye!" << endl;
			break;
		default:
			cout << "invaild option" << endl;
			break;
		}
	} while (option != 4);
	delete[]arr;
}

bool IsEmpty(int size)
{
	//your code…
}

void Print(Trip* arr, int size)
{
	//your code…
}

void EditTrip(Trip* arr, int size)
{
	//your code…
}

Trip* AddTrip(Trip* arr, int size)
{
	//your code…
}