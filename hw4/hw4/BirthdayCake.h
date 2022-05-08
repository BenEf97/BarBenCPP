#pragma once
#include "Cake.h"


class BirthdayCake : public Cake
{
	char* text;
public:
	BirthdayCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * text);
	BirthdayCake(const BirthdayCake &c);
	void setExpDate(Date d);
	void setHeight(double h);
	void setPrice(double p);
	void setGluten(bool op);
	void setText(const char* text);
	void setStorage(int s);
	Date getDate() const;
	double getHeight() const;
	double getPrice() const;
	bool getGluten() const;
	int getStorage() const;
	const char* getText() const;
	const int getDiameter() const;
	friend ostream& operator<<(ostream& os, const BirthdayCake& c);
	bool operator == (const BirthdayCake c) const;
	const BirthdayCake& operator+=(int increment);
	const BirthdayCake& operator=(const BirthdayCake &c);
	~BirthdayCake();
};

