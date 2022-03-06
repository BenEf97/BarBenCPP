//Q3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

char** StringBreakDown(char* str, int* size);

void main() {
	//init variables
	char* str;
	int* size=NULL;
	str = new char[16];
	strcpy(str, "I hate homework");
	char** newStr = StringBreakDown(str, size);

	//error here also, size is null and does not have a value.this is for debug
	for (int i = 0; i < *size; i++)
	{
		puts(newStr[i]);
		cout << '\n' << endl;
		delete(newStr[i]);
	}
	delete(str);
	delete(newStr);
}


//Q3: The function gets a string and breaks it down to words. Returns a new array of strings.
char** StringBreakDown(char* str, int* size)
{
	//init variables
	char** NewStr;

	//assuming there is at least one word in the string.
	int newsize = 1;

	//count how many words in the string
	for (int i = 0; str[i] != NULL; i++)
	{
		if (str[i] == ' ' || str[i] == '\n')
		{
			newsize++;
		}
	}

	//allocating memory for the size
	size = new int[newsize];
	*size = newsize;

	//allocating memory for the string
	NewStr = new char*[(*size)];

	int j, k;
	j = k = 0;

	/*The problem is here, I don't know if i copied it right.*/
	//getting the size of each word, and allocating it accordingly.
	for (int i=0; i < *size; j++)
	{

		//End of the word
		if (str[j] == ' ' || str[j] == '\n')
		{
			//Allocating memory
			NewStr[i] = new char[j+1];

			//Copying the ammount of characters from the k'th spot, size of j.
			strncpy(NewStr[i], &str[k], j);

			k = j+1;
			i++;
		}
	}

	return NewStr;

}