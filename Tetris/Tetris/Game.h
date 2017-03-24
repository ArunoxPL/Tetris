#pragma once
#include <SFML/Graphics.hpp>
#include "Frog.h"
#include "Truck.h"
class Game
{
public:
	Game();
	~Game();

	void Loop();
private:
	sf::RenderWindow *window;
	Truck *truck;
	Frog *frog;
};

