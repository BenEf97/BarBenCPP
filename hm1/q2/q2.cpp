//Q2	--IsArithmeticProgression--

#include <iostream>
using namespace std;

//Functions declarations
bool IsArithmeticProgression(int *Array, int size=3);

void main() {
	int *NumArray;
	int size;

	//Asking for the size of the array.
	cout << "How many numbers? " << endl;
	cin >> size;

	//The minimal size is 3.
	if (size < 3) size = 3;

	//Memory allocation
	NumArray = new int[size];

	//Asking for numbers input
	cout << "Please enter " << size << "numbers:\n" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> NumArray[i];
	}

	//using the function
	if (IsArithmeticProgression(NumArray,size))
		cout << "The array is an arithmetic sequence.\n" << endl;
	else cout << "The array isn't an arithmetic sequence.\n" << endl;

	//deleting alllocated memory
	delete (NumArray);

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
