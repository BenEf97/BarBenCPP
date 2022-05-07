#pragma once
#include "Date.h"
class Cake
{
	Date expiryDate;
	const int diameter;
	double height;
	double price;
	int storage;//1 cooler, 2 freezer
	bool glutenFree;
public:
	Cake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree);
	friend ostream& operator<<(ostream& os, const Cake& c);
	bool operator == (const Cake c) const;
	const Cake& operator+=(int increment);

};