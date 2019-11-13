#pragma once
#include <SFML/Graphics.hpp>
class Projectile
{
public:
	Projectile();
	sf::RectangleShape rect;
	int direction = 0;
	void update();
	int lifetime = 5;
	int currentframe = 0;
};

