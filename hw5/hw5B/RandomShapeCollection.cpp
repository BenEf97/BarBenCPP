#include "RandomShapeCollection.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <typeinfo>



RandomShapeCollection::RandomShapeCollection(int ShapeNum, int width, int height)
{
	//init variables
	int RandNum, xPos, yPos, radius, randH, randW;

	//Check input, if one of the conditions is invalid will throw 0
	try
	{
		if (ShapeNum <= 0 || width <= 0 || height <= 0)
		{
			throw 0;
		}
	}

	//catch if the input is invalid, and print
	catch (int temp)
	{
		std::cout << "Invalid number!" << std::endl;
	}

	//assing and allocating memory
	shapeCount = ShapeNum;
	shapes = new sf::Shape*[shapeCount];

	for (int i = 0; i < shapeCount; i++)
	{
		//Generating random numbers
		RandNum = (rand() % 3) + 1;
		xPos = (rand() % width*0.75) + 1;
		yPos = (rand() % height*0.75) + 1;
		radius = (rand() % 70) + 1;
		randH = (rand() % 70) + 1;
		randW = (rand() % 70) + 1;

	//Circle
		if (RandNum == 1)
		{
			sf::CircleShape* cshape = new sf::CircleShape(float(radius));
			shapes[i] = cshape;
			(*shapes[i]).setPosition(sf::Vector2f(xPos, yPos));
		}
		//Rectangle
		if (RandNum == 2)
		{
			//debug: check which way is right
			shapes[i] = new sf::RectangleShape(sf::Vector2f(randW, randH));
			(*shapes[i]).setPosition(sf::Vector2f(xPos, yPos));
		}
		//Triangle
		if (RandNum == 3)
		{
			sf::CircleShape* cshape3 = new sf::CircleShape(float(radius), 3);
			shapes[i] = cshape3;
			(*shapes[i]).setPosition(sf::Vector2f(xPos, yPos));
		}
	}
}

void RandomShapeCollection::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < shapeCount; i++)
	{
		//Draw circle,default point count is 30
		if (typeid(*shapes[i]).name() == typeid(sf::CircleShape).name()&&(shapes[i]->getPointCount()==30)) 
			(*shapes[i]).setFillColor(sf::Color::Blue);

		//Draw triangle
		if (typeid(*shapes[i]).name() == typeid(sf::CircleShape).name() && shapes[i]->getPointCount() == 3)
			(*shapes[i]).setFillColor(sf::Color::Yellow);

		//Draw rectangle
		if (typeid(*shapes[i]).name() == typeid(sf::RectangleShape).name())
			(*shapes[i]).setFillColor(sf::Color::Green);

		//Draw the shape
		target.draw(*shapes[i]);
	}
}


RandomShapeCollection::~RandomShapeCollection()
{
	for (int i = 0; i < shapeCount; i++)
	{
		delete[] shapes[i];
	}
	delete[] shapes;
}
