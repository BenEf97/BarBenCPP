#include "MousseCake.h"

//Constructor
MousseCake::MousseCake(Date expiryDate, const int diameter, double height, double price, int storage, bool glutenFree, const char * taste):Cake (expiryDate, diameter, height, price, storage, glutenFree)
{
	cout << "In MousseCake(expiryDate, diameter, height, price, storage, glutenFree, taste)" << endl;
	this->taste = new char[strlen(taste)+1];
	strcpy(this->taste, taste);
	
}

//Copy Constructor
MousseCake::MousseCake(const MousseCake &c) : Cake(c)
{
	cout << "In MousseCake(const MousseCake &c)" << endl;
	taste = new char[strlen(c.taste) + 1];
	strcpy(taste, c.taste);
}

//Set ExpiryDate
void MousseCake::setExpDate(Date d)
{
	expiryDate = d;
}

//Set Height
void MousseCake::setHeight(double h)
{
	height = h;
}

//Set Price
void MousseCake::setPrice(double p)
{
	price = p;
}

//Set glutenFree
void MousseCake::setGluten(bool op)
{
	glutenFree = op;
}

//Set Taste
void MousseCake::setTaste(const char * taste)
{
	delete[] this->taste;
	this->taste = new char[strlen(taste) + 1];
	strcpy_s(this->taste, strlen(taste) , taste);
}

//Set Storage
void MousseCake::setStorage(int s)
{
	storage = s;
}

//Return Date
Date MousseCake::getDate() const
{
	return Date();
}

//Return Height
double MousseCake::getHeight() const
{
	return height;
}

//Return Price
double MousseCake::getPrice() const
{
	return price;
}

//Return glutenFree
bool MousseCake::getGluten() const
{
	return glutenFree;
}

//Return Taste
const char * MousseCake::getTaste() const
{
	return taste;
}

//Return Diameter
const int MousseCake::getDiameter() const
{
	return diameter;
}

//Return Storage
int MousseCake::getStorage() const
{
	return storage;
}

//Operator == for MousseCake check if two mousse cakes are equal
bool MousseCake::operator==(const MousseCake c) const
{
	cout << "In MousseCake::operator==(const MousseCake c)" << endl;
	if (this->diameter==c.diameter&&this->glutenFree==c.glutenFree&&height==c.height&&price==c.price&&storage==c.storage)
	{
		if (!strcmp(taste, c.taste))
			return true;
	}
	else
	return false;
}

//Operator += for MousseCake increment for price
const MousseCake & MousseCake::operator+=(int increment)
{
	cout << "In MousseCake & MousseCake::operator+=(int increment)" << endl;
Cake::operator += (increment);
	return *this;
}

//Operator = for MousseCake
const MousseCake & MousseCake::operator=(const MousseCake & c)
{
	cout << "In MousseCake & MousseCake::operator=(const MousseCake & c)" << endl;
	Cake:: operator=(c);
	strcpy(taste, c.taste);
	return *this;
}

//Destructor
MousseCake::~MousseCake()
{
	cout << "In ~MousseCake()" << endl;
	taste = NULL;
	delete[] taste;
}

//Operator << for MousseCake (print)
ostream & operator<<(ostream & os, const MousseCake & c)
{

	os <<(Cake&)c<<"Taste: "<< c.taste<<endl;
	return os;
}
