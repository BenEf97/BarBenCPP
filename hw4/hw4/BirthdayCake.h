#pragma once
#include "Cake.h"


class BirthdayCake : public Cake
{
	char* text;
public:
	BirthdayCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * text);
	BirthdayCake(const BirthdayCake &c);

};

