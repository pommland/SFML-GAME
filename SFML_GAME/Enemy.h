#pragma once
#include <SFML/Graphics.hpp>
#include  "Animation.h"
#include "wall.h"
class Enemy
{
public:
	Enemy();
	void updateCollision();
	int hp = 10;
	int direction = 0;
	bool aggressive = false;

	sf::Sprite sprite;
	sf::RectangleShape rect;

	int enemyAttack = 1;

	sf::RectangleShape rectfoot;
	sf::RectangleShape rectcentral;
	sf::RectangleShape rectfrontAttack;
	sf::RectangleShape rectleftAttack;
	sf::RectangleShape rectrightAttack;
	sf::RectangleShape rectdownAttack;
	float animationFrameWalk = 0;
	float animationFrameAttack = 0;
	float animationFrameStopWalk = 0;


	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;


};


