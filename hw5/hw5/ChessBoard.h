#pragma once
#include <SFML/Graphics.hpp>

class ChessBoard:public sf::Drawable
{
private:
	sf::RectangleShape matrix[8][8];
public:
	ChessBoard(int width,int height);
};

