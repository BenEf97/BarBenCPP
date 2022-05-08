#pragma once
#include "Cake.h"
class MousseCake : public Cake
{
	char* taste;
public:
	MousseCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * taste);
	MousseCake(const MousseCake &c);
};

