#include "Game.h"


Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML Starter Template", sf::Style::Close);

	frog = new Frog(window->getSize());

	truck = new Truck(window->getSize(), 0, window->getSize().y / 2);
}

void Game::Loop()
{
	while (window->isOpen())
	{
		// handle events
		sf::Event event;

		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				frog->Move(event);
			}
		}
		// update

		truck->Move(window->getSize());

		if (frog->GetShape().getGlobalBounds().intersects(truck->GetShape().getGlobalBounds()))
		{
			window->close();
			//frog.GetShape().setPosition(sf::Vector2f(frog.getPosition().x, window.getSize().y - frog.getSize().y));
		}


		window->clear();

		// draw SFML content

		truck->Draw(*window);
		frog->Draw(*window);
		window->display();
	}

}


Game::~Game()
{
}
