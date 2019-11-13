#pragma once
#include <SFML/Graphics.hpp>
#include  "Animation.h"

class Enemy
{
public:
	Enemy();
	void updateCollision();
	int hp = 10;
	int direction = 0;

	sf::Sprite sprite;
	sf::RectangleShape rect;
};


