#pragma once
#include "Cake.h"
class MousseCake : public Cake
{
	char* taste;
public:
	MousseCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * taste);
	MousseCake(const MousseCake &c);
	void setExpDate(Date d);
	void setHeight(double h);
	void setPrice(double p);
	void setGluten(bool op);
	void setTaste(const char* taste);
	void setStorage(int s);
	Date getDate() const;
	double getHeight() const;
	double getPrice() const;
	bool getGluten() const;
	const char* getTaste() const;
	const int getDiameter() const;
	int getStorage() const;
	friend ostream& operator<<(ostream& os, const MousseCake& c);
	bool operator == (const MousseCake c) const;
	const MousseCake& operator+=(int increment);
	const MousseCake& operator=(const MousseCake &c);
	~MousseCake();
};

