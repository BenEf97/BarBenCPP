#include "MousseCake.h"

MousseCake::MousseCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * taste):Cake (expiryDate, diameter, height, price, storage, glutenFree)
{
	cout << "In MousseCake(expiryDate, diameter, height, price, storage, glutenFree, taste)" << endl;
	this->taste = new char[strlen(taste)+1];
	strcpy(this->taste, taste);
	delete[] taste;
}

//copy constructor
MousseCake::MousseCake(const MousseCake &c) : Cake(c)
{
	taste = new char[strlen(c.taste) + 1];
	strcpy(taste, c.taste);
}