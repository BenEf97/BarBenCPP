//Q1	--WeightedAverage--

#include <iostream>
using namespace std;
const int ArrSize=4;

//Functions declarations
double WeightedAverage(double *ValArr,double *WeighArr);
void MemAllocFail();

void main()
{
	//Initlize values, memory allocation with constat size.
	double *valueArr = new double[ArrSize] {2,3,4,5};
	//If the allocation fails
	if (!valueArr) MemAllocFail();

	double *weightArr = new double[ArrSize] {0.2,0.3,0.4,0.5};
	if (!weightArr) MemAllocFail();;

	//Printing the weighted average
	cout << "The weighted average is: " << WeightedAverage(valueArr, weightArr) << endl;

	//Deleting allocated memory
	delete (valueArr);
	delete (weightArr);
}


//The function recives a value array and a weight array, returns the weighted average of them.
//Using the formula of x=sum(val*weigh)/sum(weigh) from 0 to n-1
double WeightedAverage(double *ValArr, double *WeighArr)
{
	//Init variables, UpperSum is the Numeratror and the BottomSum is the denominator.
	double UpperSum=0, BottomSum=0;

	//Summing the numerator and the denominator
	for (int i = 0; i < ArrSize; i++)
	{
		UpperSum += ValArr[i]*WeighArr[i];
		BottomSum += WeighArr[i];
	}
	//Returning the average.
	return (UpperSum / BottomSum);
}

//Prints error messege, and closing the program.
void MemAllocFail()
{
	cout << "Out of memory! Closing the program." << endl;
	exit(1);
}