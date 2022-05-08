#include "BirthdayCake.h"

BirthdayCake::BirthdayCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * text) :Cake(expiryDate, diameter, height, price, storage, glutenFree)
{
	cout << "In BirthdayCake(expiryDate, diameter, height, price, storage, glutenFree, text)" << endl;
	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);
	delete[] text;
}

//copy constructor
BirthdayCake::BirthdayCake(const BirthdayCake &c) : Cake(c)
{
	text = new char[strlen(c.text) + 1];
	strcpy(text, c.text);
}
