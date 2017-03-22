#include <SFML/Graphics.hpp>
#include "Frog.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Starter Template", sf::Style::Close);

	Frog frog(window.getSize());
	
	sf::RectangleShape truck;

	truck.setSize(sf::Vector2f(120, 60));
	truck.setFillColor(sf::Color::Red);
	truck.setPosition(sf::Vector2f(truck.getPosition().x, window.getSize().y / 2 - truck.getSize().y));
	

	while (window.isOpen())
	{
		// handle events
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				frog.Move(event);
			}
		}

		// update
		truck.move(0.2, 0);

		if (truck.getPosition().x > window.getSize().x)
		{
			truck.setPosition(sf::Vector2f(-truck.getSize().x, window.getSize().y / 2 - truck.getSize().y));
		}

		if (frog.GetShape().getGlobalBounds().intersects(truck.getGlobalBounds()))
		{
			window.close();
			//frog.GetShape().setPosition(sf::Vector2f(frog.getPosition().x, window.getSize().y - frog.getSize().y));
		}

		window.clear();

		// draw SFML content
		
		window.draw(truck);
		frog.Draw(window);
		window.display();
	}

	return EXIT_SUCCESS;
}