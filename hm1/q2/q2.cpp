//Q2	--IsArithmeticProgression--

#include <iostream>
using namespace std;

//Functions declarations
bool IsArithmeticProgression(char *Array, int size=3);
bool IsArithmeticProgression(int *Array, int size = 3);

void main() {
	int *NumArray;
	int sizeNum;

	//Asking for the size of the array.
	cout << "How many numbers? " << endl;
	cin >> sizeNum;

	//The minimal size is 3.
	if (sizeNum < 3) sizeNum = 3;

	//Memory allocation
	NumArray = new int[sizeNum];

	//Asking for numbers input
	cout << "Please enter " << sizeNum << " numbers:\n" << endl;
	for (int i = 0; i < sizeNum; i++)
	{
		cin >> NumArray[i];
	}

	//using the function
	if (IsArithmeticProgression(NumArray,sizeNum))
		cout << "The array is an arithmetic sequence.\n" << endl;
	else cout << "The array isn't an arithmetic sequence.\n" << endl;

	//deleting alllocated memory
	delete (NumArray);


	char *CharArray;
	int sizeChar;

	//Asking for the size of the array.
	cout << "How many characters? " << endl;
	cin >> sizeChar;

	//The minimal size is 3.
	if (sizeChar < 3) sizeChar = 3;

	//Memory allocation
	CharArray = new char[sizeChar];

	//Asking for numbers input
	cout << "Please enter " << sizeChar << " characters:\n" << endl;
	for (int i = 0; i < sizeChar; i++)
	{
		cin >> CharArray[i];
	}

	//using the function
	if (IsArithmeticProgression(CharArray, sizeChar))
		cout << "The array is an arithmetic sequence.\n" << endl;
	else cout << "The array isn't an arithmetic sequence.\n" << endl;

	//deleting alllocated memory
	delete (CharArray);
}


//Checks if a sequence is an arithmetic progression ,returns True if so, else returns else False
bool IsArithmeticProgression(int *Array, int size) {
	//Init variables, diff is the difference of successive numbers, and the value will be the differnce between the first and second elemnts.
	int diff=Array[1]-Array[0];
	
	//Checking if the difference is constant.
	for (int i = 0; i+1 < size; i++)
	{
		//if the difference is not constant, will return false.
		if (diff != (Array[i + 1] - Array[i]))
			return false;
	}
	//The sequence is an arithmetic progression.
	return true;
}

//Q2.b- For strings. Gets an array of chars and checks if is an arithmetic progression.
bool IsArithmeticProgression(char *Array, int size)
{
	//Init variables, diff is the difference of successive numbers, and the value will be the differnce between the first and second elemnts.
	int diff = Array[1] - Array[0];

	//Checking if the difference is constant.
	for (int i = 0; i + 1 < size; i++)
	{
		//if the difference is not constant, will return false.
		if (diff != (Array[i + 1] - Array[i]))
			return false;
	}
	//The sequence is an arithmetic progression.
	return true;
}

