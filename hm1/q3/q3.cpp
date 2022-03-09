//Q3

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

char** StringBreakDown(char* str, int& size);
char* DoubleSizeStr(char* Array);

void main() {
	//init variables
	char* str;
	int size=0;
	str = new char[16];
	strcpy(str, "I hate homework");
	char** newStr = StringBreakDown(str, size);
	for (int i = 0; i < size; i++) //check for StringBreakDown
	{
		cout << newStr[i] << endl;
	}
	for (int i = 0; i < size; i++)
	{
		char* tmp= DoubleSizeStr(newStr[i]);
		delete(newStr[i]);
		newStr[i] = tmp;
	}
	
	for (int i = 0; i < size; i++) //check for DoubleSizeStr
	{
		cout << newStr[i] << endl;
		delete(newStr[i]);
	}
	delete(str);
	delete(newStr);
}


//Q3a: The function gets a string and breaks it down to words. Returns a new array of strings.
char** StringBreakDown(char* str, int& size)
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
	//size = new int[newsize];
	size = newsize;

	//allocating memory for the string
	NewStr = new char*[(size)];
	int j, k;
	j = k = 0;
	//allocating memory to each pointer in the Array
	for (int i = 0; 1 ; i++)
	{
		if (str[i] == ' ' || str[i] == '\n'|| str[i] == NULL)
		{
			NewStr[k] = new char[(j + 1)];
			k++;
			j = 0;
			if (str[i] == NULL) break;
			continue;
		}
		j++;
	}

	
	j = k = 0;

	
	//getting the size of each word, and allocating it accordingly.
	for (int i=0; i < size;)
	{

		//End of the word
		if (str[j] == ' ' || str[j] == '\n'||str[j] == NULL)
		{
			
			//Copying the ammount of characters from the k'th spot, size of j.
			int p = j - k;
			strncpy(NewStr[i], &str[k], p);
			NewStr[i][p] = '\0';
			k = j+1;
			i++;
			if (str[j] == NULL) break;
		}
		j++;
	}

	return NewStr;

}
//Q3b: getting each sring of a word and double it, then return it
char* DoubleSizeStr(char* Array)
{
	//getting size of string, then allocating tmp pointer, then double the string and copy it into newstr and return it
		int strsize = strlen(Array);
		char* newstr = new char[(2*strsize)+1];
		strcpy(newstr, Array);
		strcat(newstr, Array);
		return newstr;
		
}