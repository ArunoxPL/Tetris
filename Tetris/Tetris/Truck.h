#pragma once
#include <SFML/Graphics.hpp>

class Truck
{
public:
	Truck( sf::Vector2u size, float posX, float posY);
	void Draw( sf::RenderWindow &window);
	void Move(sf::Vector2u sice);
	sf::RectangleShape GetShape();

private:
	sf::RectangleShape truck;

	float originalPosX, originalPosY;
	
};

