#include <SFML/Graphics.hpp>
#include "ChessBoard.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

int main()
{
	ChessBoard* myBoard = new ChessBoard(WINDOW_WIDTH, WINDOW_HEIGHT);
	// create the window
	sf::RenderWindow window(\
							sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),\
							"ChessBoard",\
							7U,\
							sf::ContextSettings(0U,0U,16U,1U,1U,0U,false));

	// run the main loop
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		// draw it
		window.clear();
		window.draw(*myBoard);
		window.display();
	}

	delete myBoard;
	return 0;
}