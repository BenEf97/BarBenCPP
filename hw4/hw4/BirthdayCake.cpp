#include "BirthdayCake.h"

//constuctor
BirthdayCake::BirthdayCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * text) :Cake(expiryDate, diameter, height, price, storage, glutenFree)
{
	cout << "In BirthdayCake(expiryDate, diameter, height, price, storage, glutenFree, text)" << endl;
	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);
}

//copy constructor
BirthdayCake::BirthdayCake(const BirthdayCake &c) : Cake(c)
{
	cout << "In BirthdayCake(const BirthdayCake &c)" << endl;
	text = new char[strlen(c.text) + 1];
	strcpy(text, c.text);
}


//set expiry date
void BirthdayCake::setExpDate(Date d)
{
	expiryDate = d;
}

//set height
void BirthdayCake::setHeight(double h)
{
	height = h;
}

//set price
void BirthdayCake::setPrice(double p)
{
	price = p;
}

//set gluten free or not
void BirthdayCake::setGluten(bool op)
{
	glutenFree = op;
}

//set text
void BirthdayCake::setText(const char * text)
{
	delete[] this->text;
	this->text= new char[strlen(text) + 1];
	strcpy_s(this->text, strlen(text), text);
}

//set storage method
void BirthdayCake::setStorage(int s)
{
	storage = s;
}

//returns date
Date BirthdayCake::getDate() const
{
	return Date();
}

//return height
double BirthdayCake::getHeight() const
{
	return height;
}

//returns price
double BirthdayCake::getPrice() const
{
	return price;
}

//returns gluten free or not
bool BirthdayCake::getGluten() const
{
	return glutenFree;
}

//returns storage method
int BirthdayCake::getStorage() const
{
	return storage;
}

//returns text on cake
const char * BirthdayCake::getText() const
{
	return text;
}

//returns diameter
const int BirthdayCake::getDiameter() const
{
	return diameter;
}

//compares two birthday cakes
bool BirthdayCake::operator==(const BirthdayCake c) const
{
	cout << "In BirthdayCake::operator==(const BirthdayCake c)" << endl;
	if (Cake::operator==(c))
	{
		//check if the text is the same
		if (!strcmp(text, c.text))
			return true;
	}
	else
		return false;
}

//increment for price
const BirthdayCake & BirthdayCake::operator+=(int increment)
{
	cout << "In BirthdayCake & BirthdayCake::operator+=(int increment)" << endl;
	Cake::operator += (increment);
	return *this;
}

//assign operator
const BirthdayCake & BirthdayCake::operator=(const BirthdayCake & c)
{
	cout << "In BirthdayCake & BirthdayCake::operator=(const BirthdayCake & c)" << endl;
	//using base operator
	Cake:: operator=(c);
	strcpy(text, c.text);
	return *this;
}

//destructor
BirthdayCake::~BirthdayCake()
{
	cout << "In ~BirthdayCake()" << endl;
	text = NULL;
	delete[] text;
}

//printing method
ostream & operator<<(ostream & os, const BirthdayCake & c)
{
	os << (Cake&)c<<"Text: " << c.text << endl;
	return os;
}
