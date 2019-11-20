#pragma once
#include <SFML/Graphics.hpp>
#include  "Animation.h"
#include "SFML/Audio.hpp"
class Player
{
private:

	float keytime;
	const float keytimeMax;

public:
	Player();
	void updateCollision();
	void updateMovement(int *);
	void updateStopMovement();
	sf::Sprite sprite;
	sf::RectangleShape rect;
	sf::RectangleShape rectfoot;
	sf::RectangleShape rectcentral;
	sf::RectangleShape rectfrontAttack;
	sf::RectangleShape rectleftAttack;
	sf::RectangleShape rectrightAttack;
	sf::RectangleShape rectdownAttack;

	bool checkPressed = false;
	int checkButtonAttack;
	int direction = 0;
	float animationFrameWalk = 0;
	float animationFrameAttack = 0;
	float animationFrameStopWalk = 0;
	float count = 0;
	sf::SoundBuffer playerBuffer;
	sf::Sound playerSound;

	sf::Sound playerAttackSoundobj;
	sf::SoundBuffer playerAttackSound;

	//sf::SoundBuffer deadsound;
	//sf::Sound deadsoundobj;

	sf::RectangleShape HPbarobj;
	sf::Texture  HPbarobjTexture;

	sf::RectangleShape iconobj1;
	sf::Texture iconPunchobjTexture1;
	sf::Texture iconLongswordobjTexture1;
	sf::Texture shirtobjTexture2;
	sf::Texture yellowshirtTexture2;
	sf::RectangleShape iconobj2;
	sf::RectangleShape iconobj3;
	sf::RectangleShape iconobj4;
	sf::Texture iconobjTexture2;


	 int myHP = 45;
	sf::RectangleShape hp;

	int absAttack = 128;
	int topAttack =4 ;
	int downAttack = 6;
	int leftAttack = 5;
	int rightAttack = 7;

	const bool getKeyTime();
	void updateKeyTime(const float& dt);

	char	lastpresses = 'E';

	sf::Vector2f GetPosotion() { return rect.getPosition(); }
	void setTexture();
	
	sf::RectangleShape activeItem;
	sf::RectangleShape activeItem2;

	//int 
	//direction = 0;

	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;


	int deadAnimation = 0;
	int speed = 1;
};

