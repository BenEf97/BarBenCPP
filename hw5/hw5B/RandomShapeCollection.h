#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
class RandomShapeCollection:public sf::Drawable
{
private:
	sf::Shape **shapes;
	int shapeCount;
public:
	RandomShapeCollection(int ShapeNum,int width,int height);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~RandomShapeCollection();
};

