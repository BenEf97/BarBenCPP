#include "Cake.h"
//using namespace std;
//#include <iostream>


//constructor
Cake::Cake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree):expiryDate(expiryDate),diameter(diameter),height(height),price(price),storage(storage),glutenFree(glutenFree) //here init for members of class debug!
{
	
	cout << "In Cake(expiryDate, diameter, height, price, storage, glutenFree)" << endl;

}

//copy constructor
Cake::Cake(const Cake &c):expiryDate(c.expiryDate), diameter(c.diameter), height(c.height), price(c.price), storage(c.storage), glutenFree(c.glutenFree)
{
	cout << "In Cake(const Cake &c)" << endl;
}

//== operator, compares two cakes.
bool Cake::operator==(const Cake c) const
{
	cout << "In Cake::operator==(const Cake c)" << endl;
	if (expiryDate == c.expiryDate &&diameter == c.diameter&&height == c.height&&price == c.price&&storage == c.storage&&glutenFree == c.glutenFree)
		return true;
	else return false;
}

//increment for price
const Cake & Cake::operator+=(int increment)
{
	cout << "In Cake & Cake::operator+=(int increment)" << endl;
	price += increment;
	return *this;
}

//assign operator, diameter can't be changed
const Cake & Cake::operator=(const Cake & c)
{
	cout << "In Cake & Cake::operator=(const Cake & c)" << endl;
	expiryDate = c.expiryDate;
	height = c.height;
	price = c.price;
	storage = c.storage;
	glutenFree = c.glutenFree;
	//diameter is a const
	return *this;
}

ostream & operator<<(ostream & os, const Cake & c)
{
	os << "Cake:\nExpiry Date: " << c.expiryDate << "Diameter: " << c.diameter << "\nHeight: " << c.height << "\nPrice: " << c.price << "\nStorage: ";
	//checks storage
	if (c.storage == 1)
		os << "refrigerator (1)";
	else os << "freezer (2)";

	//check gluten free
	os << "\nGluten free: ";
	if (c.glutenFree)
		os << "True" << endl;
	else os << "False" << endl;

	return os;
}
