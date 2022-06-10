#include "ChessBoard.h"
#include <SFML/Graphics.hpp>

//B. Constructor.  Gets pixels width and height and sets a chess board.
ChessBoard::ChessBoard(int width, int height)
{
	int blockW = width / 8;
	int blockH = height / 8;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			//determine the color order
			if (i % 2)
			{
				matrix[i][j].setSize(sf::Vector2f(blockW, blockH));
				matrix[i][j].setPosition(sf::Vector2f(blockW*j, blockH*i));
				matrix[i][j].setFillColor(sf::Color::Cyan);
				j++;
				matrix[i][j].setSize(sf::Vector2f(blockW, blockH));
				matrix[i][j].setPosition(sf::Vector2f(blockW*j, blockH*i));
				matrix[i][j].setFillColor(sf::Color::White);
			}
			else
			{
				matrix[i][j].setSize(sf::Vector2f(blockW, blockH));
				matrix[i][j].setPosition(sf::Vector2f(blockW*j, blockH*i));
				matrix[i][j].setFillColor(sf::Color::White);
				j++;
				matrix[i][j].setSize(sf::Vector2f(blockW, blockH));
				matrix[i][j].setPosition(sf::Vector2f(blockW*j, blockH*i));
				matrix[i][j].setFillColor(sf::Color::Cyan);
			}
		}
	}
}

//C. Virtual function to draw the board.
void ChessBoard::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			target.draw(matrix[i][j]);
		}
	}
}
