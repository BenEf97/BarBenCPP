#include <SFML/Graphics.hpp>
#include "RandomShapeCollection.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

int main()
{
	RandomShapeCollection* shapes = new RandomShapeCollection(10, WINDOW_WIDTH, WINDOW_HEIGHT);
	// create the window
	sf::RenderWindow window(\
							sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),\
							"RandomShapes",\
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
		window.draw(*shapes);
		window.display();
	}

	delete shapes;
	return 0;
}