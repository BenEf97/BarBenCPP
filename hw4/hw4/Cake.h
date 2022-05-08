#pragma once
#include "Date.h"
class Cake //The cake is a lie
{
protected:
	Date expiryDate;
	const int diameter;
	double height;
	double price;
	int storage;//1 cooler, 2 freezer
	bool glutenFree;
public:
	Cake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree);
	Cake(const Cake &c);
	friend ostream& operator<<(ostream& os, const Cake& c);
	bool operator == (const Cake c) const;
	const Cake& operator+=(int increment);
	const Cake& operator=(const Cake &c);


};