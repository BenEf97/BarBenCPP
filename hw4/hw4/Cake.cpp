#include "Cake.h"
//using namespace std;
//#include <iostream>

Cake::Cake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree)
{
	this->expiryDate = expiryDate;
	this->diameter = diameter;//how do you init a constant?
	this->height = height;
	this->price = price;
	this->storage = storage;
	this->glutenFree = glutenFree;
}

bool Cake::operator==(const Cake c) const
{
	if (expiryDate == c.expiryDate &&diameter == c.diameter&&height == c.height&&price == c.price&&storage == c.storage&&glutenFree == c.glutenFree)
		return true;
	else return false;
}

const Cake & Cake::operator+=(int increment)
{
	price += increment;
	return *this;
}

ostream & operator<<(ostream & os, const Cake & c)
{
	os << "Expiry Date: " << c.expiryDate << "Diameter: " << c.diameter << "\nHeight: " << c.height << "\nPrice: " << c.price << "Storage: ";
	//checks storage
	if (c.storage == 1)
		os << "refrigerator (1)";
	else os << "freezer (2)";

	os << "\Gluten free: ";
	if (c.glutenFree)
		os << "True" << endl;
	else os << "False" << endl;

	return os;
}
