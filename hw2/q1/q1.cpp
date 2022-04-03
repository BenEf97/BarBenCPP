#define _CRT_SECURE_NO_WARNINGS
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
	system("pause");
}


//Checks if the the array is empty, returns true or false.
bool IsEmpty(int size)
{
	if (size == 0)
	{
		cout << "The array is empty!\n" << endl;
		return true;
	}
	else return false;
}

void Print(Trip* arr, int size)
{
	//Checks if the array is empty
	if (IsEmpty(size))
		return;
	cout << "List Of Trips:" << endl;
	//Loop for printing all the elements in the array
	for (int i = 0; i < size; i++)
	{
		arr[i].PrintTrip();
	}

}

//Edit trip
void EditTrip(Trip* arr, int size)
{
	int numEdit;
	char option;

	//Checks if the array is empty
	if (IsEmpty(size))
		return;

	//Output for the user
	cout << "Please enter the number of trip that you would like to edit: ";
	cin >> numEdit;


	//Finding the number of the trip in the array
	for (int i=0;i<size;i++)
	{
		//The number was found
		if (arr[i].getNoT()==numEdit)
		{
			//assuming for valid input
			cout << "Would you like to change the destinaton? y/n ";
			cin.ignore();
			cin >> option;

			//Option for yes
			if (option=='y')
			{
				//Temp name for new trip
				char tempName[50];
				cout << "Please Enter new destination: ";

				//Assuming for valid input
				cin.ignore();
				cin.getline(tempName, 49,'\n');
				arr[i].setDes(tempName);
			}


			//assuming for valid input
			cout << "Would you like to change the date? y/n ";
			//cin.clear();
			cin >> option;
			
			if (option == 'y')
			{
				//Output for user to enter day, mpnth, year
				int d, m, y;
				cout << "Please enter new day: ";
				cin >> d;
				cout << "Please enter new month: ";
				cin >> m;
				cout << "Please enter new year: ";
				cin >> y;

				//new date object constructor
				Date newDate(d,m,y);

				//setting the new date
				arr[i].setDate(newDate);
			}
			
			//Editing complete, returns to the main.
			return;
		}
	}
	
	//Trip not found, displays output for the user.
	cout << "The trip wasn't found. Retruning to the main menu...\n" << endl;
	
}

	

Trip* AddTrip(Trip* arr, int size)
{
	//init arguments
	int numoftrip,d,m,y;
	char dest[50];

	//Output for the user, assuming for valid input.
	cout << "Please enter trip details:\nPlease enter the number of the trip: ";
	cin >> numoftrip;
	cout << "Enter Destination: ";
	cin.ignore();
	cin.getline(dest,49,'\n');
	cout << "Please enter day: ";
	cin >> d;
	cout << "Please enter month: ";
	cin >> m;
	cout << "Please enter year: ";
	cin >> y;
	Date newdate(d, m, y);

	//Checking if the original array is empty.
	
	
		Trip *newArr = new Trip[size + 1];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
		newArr[size].setNoT(numoftrip);
		newArr[size].setDes(dest);
		newArr[size].setDate(newdate);
		delete[] arr;
		return newArr;
	

}
