#include "Player.h"
#include <iostream>

Player::Player()
	: keytimeMax(5.f), keytime(0.f)
{
	rect.setSize(sf::Vector2f(32, 53));
	rect.setPosition(10, 100);
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(-16.f, -13.f);
	sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
	playerBuffer.loadFromFile("grass_0.wav");
	playerSound.setBuffer(playerBuffer);

	playerAttackSound.loadFromFile("Explosion6.wav");
	playerAttackSoundobj.setBuffer(playerAttackSound);
	
	//deadsound.loadFromFile("deadsound.ogg");
	//deadsoundobj.setBuffer(deadsound);

	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(-1.f);

	rectfoot.setSize(sf::Vector2f(5, 5));
	//rectfoot.setPosition(24, 132);
	rectfoot.setOrigin(-16.f, -13.f);
	rectfoot.setFillColor(sf::Color::Transparent);
	rectfoot.setOutlineColor(sf::Color::Green);
	rectfoot.setOutlineThickness(-1.f);

	rectcentral.setSize(sf::Vector2f(26, 26));
	//rectfoot.setPosition(24, 132);
	rectcentral.setOrigin(-16.f, -13.f);
	rectcentral.setFillColor(sf::Color::Transparent);
	rectcentral.setOutlineColor(sf::Color::Magenta);
	rectcentral.setOutlineThickness(-1.f);




	rectdownAttack.setSize(sf::Vector2f(88, 48));
	//rectfoot.setPosition(24, 132);
	rectdownAttack.setOrigin(-16.f, -13.f);
	rectdownAttack.setFillColor(sf::Color::Transparent);
	rectdownAttack.setOutlineColor(sf::Color::Red);
	rectdownAttack.setOutlineThickness(-1.f);



	rectleftAttack.setSize(sf::Vector2f(80, 48));
	rectleftAttack.setFillColor(sf::Color::Transparent);
	rectleftAttack.setOutlineColor(sf::Color::Red);
	rectleftAttack.setOutlineThickness(-1.f);


	rectrightAttack.setSize(sf::Vector2f(80, 48));
	rectrightAttack.setFillColor(sf::Color::Transparent);
	rectrightAttack.setOutlineColor(sf::Color::Blue);
	rectrightAttack.setOutlineThickness(-1.f);




	iconPunchobjTexture1.loadFromFile("punch.png");
	iconLongswordobjTexture1.loadFromFile("Longsword.png");

	iconobj1.setSize(sf::Vector2f(15.0f, 15.0f));
	iconobj1.setTexture(&iconPunchobjTexture1);

	iconobj2.setSize(sf::Vector2f(15.0f, 15.0f));
	iconobj2.setTexture(&iconLongswordobjTexture1);


	yellowshirtTexture2.loadFromFile("yellowshirt.png");
	shirtobjTexture2.loadFromFile("shirt.png");

	iconobj3.setSize(sf::Vector2f(15.0f, 15.0f));
	iconobj3.setTexture(&yellowshirtTexture2);

	iconobj4.setSize(sf::Vector2f(15.0f, 15.0f));
	iconobj4.setTexture(&shirtobjTexture2);


	Redsword1.loadFromFile("Redsword.png");
	greenshirt2.loadFromFile("greenshirt.png");


	iconobj5.setSize(sf::Vector2f(15.0f, 15.0f));
	iconobj5.setTexture(&Redsword1);

	iconobj6.setSize(sf::Vector2f(15.0f, 15.0f));
	iconobj6.setTexture(&greenshirt2);




	HPbarobjTexture.loadFromFile("hp.png");

	HPbarobj.setSize(sf::Vector2f(64.0f, 15.0f));
	HPbarobj.setTexture(&HPbarobjTexture);
	//HPbarobj.setOutlineColor(sf::Color::Black);
	//HPbarobj.setOutlineThickness(1.f);
	//HPbarobj.setPosition(10.f, 95.f);

	/*hpbar.setTexture(HPbar);
	sf::RectangleShape HP(sf::Vector2f(MyHP / 250, 30));
	HP.setPosition(sf::Vector2f(60, 33));

	HP.setFillColor(sf::Color::Red);
	HP.setSize(sf::Vector2f(MyHP / 260, 36));
	hpbar.setPosition(60, 33);*/

	hp.setFillColor(sf::Color::Red);
	//hp.setSize(sf::Vector2f(myHP,4));

	activeItem = iconobj1;
	activeItem2 = iconobj3;
}



void Player::updateCollision() {
	sprite.setPosition(rect.getPosition().x-32 , rect.getPosition().y-32 );
	rectfoot.setPosition(rect.getPosition().x+13,rect.getPosition().y+10 );
	HPbarobj.setPosition(rect.getPosition().x  , rect.getPosition().y );
	activeItem.setPosition(rect.getPosition().x, rect.getPosition().y+10);
	//iconobj2.setPosition(rect.getPosition().x, rect.getPosition().y + 30);
		activeItem2.setPosition(rect.getPosition().x, rect.getPosition().y + 25);
	hp.setPosition(rect.getPosition().x+13, rect.getPosition().y +4);
	hp.setSize(sf::Vector2f(myHP, 4));
	rectcentral.setPosition(rect.getPosition().x, rect.getPosition().y+10);
	rectfrontAttack.setPosition(rect.getPosition().x-32, rect.getPosition().y -22);
	rectdownAttack.setPosition(rect.getPosition().x - 32, rect.getPosition().y + 22);

	rectleftAttack.setPosition(rect.getPosition().x-32 , rect.getPosition().y+16 );
	rectrightAttack.setPosition(rect.getPosition().x + 16, rect.getPosition().y + 16);

}

void Player::updateStopMovement()
{

}

const bool Player::getKeyTime()
{
	if (this->keytime >= this->keytimeMax)
	{
		this->keytime = 0.f;
		return true;
	}
	return false;
}

void Player::updateKeyTime(const float& dt)
{
	if (this->keytime < this->keytimeMax)
	{
		this->keytime += 10.f * dt;
	}
}

void Player::setTexture()
{
	std::cout << "sad" << std::endl;
	iconobj1.setTexture(&iconLongswordobjTexture1);
}


void Player::updateMovement(int *mode) {

	if (myHP <= 0) {
		std::cout << deadAnimation << std::endl;
		if (deadAnimation > 450) {
			*mode = 2;
			return;
		}
		if (deadAnimation < 6) {
			sprite.setTextureRect(sf::IntRect(128 * (int)deadAnimation, 128 * 8, 128, 128));
		}
		deadAnimation++;
		//deadsoundobj.play();
		//music.openFromFile("deadsound.ogg");
		//music.play();
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

	}


	if (lastpresses == 'W')
	{
		sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameStopWalk, 128 * 4, 128, 128));
	
	}
	if (lastpresses == 'S')
	{
		sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameStopWalk, 128 * 6, 128, 128));
	
	}
	if (lastpresses == 'A')
	{
		sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameStopWalk, 128 * 5, 128, 128));
	
	}
	if (lastpresses == 'D')
	{
		sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameStopWalk, 128 * 7, 128, 128));
	
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			rect.move(sf::Vector2f(0, -2));
			sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 0, 128, 128));

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			rect.move(sf::Vector2f(0, 2));
			sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 2, 128, 128));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			rect.move(sf::Vector2f(2, 0));
			sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 3, 128, 128));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (canMoveLeft == true)
			{
				rect.move(sf::Vector2f(-2, 0));
				sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 1, 128, 128));
			}
			direction = 3;
			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				rect.move(sf::Vector2f(0, -5));
				sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 0, 128, 64));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				rect.move(sf::Vector2f(0, 5));
				sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 2, 128, 128));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				rect.move(sf::Vector2f(5, 0));
				sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 3, 128, 128));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				rect.move(sf::Vector2f(-5, 0));
				sprite.setTextureRect(sf::IntRect(64 * (int)animationFrameWalk, 128 * 1, 128, 128));
			}
		}
	}

	//sprite.setTextureRect(sf::IntRect(64 * 0, 64 * 6, 64, 64));
	/**/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		

		if (canMoveUp ==true)
		{
			rect.move(sf::Vector2f(0, -speed));
			sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 0, 128, 128));

		}

		
		lastpresses = 'W';
		if (animationFrameWalk == 0 && this->getKeyTime())
		{
			playerSound.play();

		}

		direction = 1;
		canMoveUp = true;
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = true;  
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		if (canMoveDown == true)
		{
			rect.move(sf::Vector2f(0, speed));
			sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 2, 128, 128));
		}

		
		lastpresses = 'S';
		if (animationFrameWalk == 0 && this->getKeyTime())

		{
			playerSound.play();

		}

		direction = 2;
		canMoveUp = true;
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = true;
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		if (canMoveLeft == true)
		{
			rect.move(sf::Vector2f(-speed, 0));
			sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 1, 128, 128));
		}

		
		lastpresses = 'A';
		if (animationFrameWalk == 0 && this->getKeyTime())
		{
			playerSound.play();

		}
		direction = 3;
		canMoveUp = true;
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = true;

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		if (canMoveRight == true)
		{
			rect.move(sf::Vector2f(speed, 0));
			sprite.setTextureRect(sf::IntRect(128 * (int)animationFrameWalk, 128 * 3, 128, 128));
		
		}

	
		lastpresses = 'D';
		if (animationFrameWalk == 0 && this->getKeyTime())
		{
			playerSound.play();

		}
		direction = 4;
		canMoveUp = true;
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = true;
	}
	//else
	//{
	//	//not moving
	//}




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
		std::cout << rect.getPosition().x << " " << rect.getPosition().y << std::endl;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		std::cout << myHP << std::endl;

	}
	


	

	//9111012



	 else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		checkPressed = true;
		if (15 / count == 1) {
			playerAttackSoundobj.play();
		}
		
		if (lastpresses == 'W')
		{
			sprite.setTextureRect(sf::IntRect(absAttack* (int)animationFrameAttack, absAttack* topAttack, absAttack, absAttack));
			if (checkPressed == true) {
				std::cout << "skks" << std::endl;
				rectfrontAttack.setSize(sf::Vector2f(88, 48));
				//rectfoot.setPosition(24, 132);
				rectfrontAttack.setOrigin(-16.f, -13.f);
				rectfrontAttack.setFillColor(sf::Color::Transparent);
				rectfrontAttack.setOutlineColor(sf::Color::Red);
				rectfrontAttack.setOutlineThickness(-1.f);
				checkPressed = false;
			}

		}
		if (lastpresses == 'S')
		{
			sprite.setTextureRect(sf::IntRect(absAttack* (int)animationFrameAttack, absAttack* downAttack, absAttack, absAttack));
		}
		if (lastpresses == 'A')
		{
			sprite.setTextureRect(sf::IntRect(absAttack* (int)animationFrameAttack, absAttack* leftAttack, absAttack, absAttack));
		}
		if (lastpresses == 'D')
		{
			sprite.setTextureRect(sf::IntRect(absAttack* (int)animationFrameAttack, absAttack* rightAttack, absAttack, absAttack));
		}
	
		checkPressed = false;
	}

	animationFrameWalk+=0.2;
	if (animationFrameWalk >= 8) {
		animationFrameWalk = 0;
	}
	animationFrameStopWalk+=0.1;
	if (animationFrameStopWalk >= 3) {
		animationFrameStopWalk = 0;
	}
	animationFrameAttack+=0.2;
	if (animationFrameAttack >= 5) {
		animationFrameAttack = 0;
	}
	count += 0.5;
	if (count >= 15.2) {
		count = 0;
	}
	
	else if (checkPressed == false)
	{
		rectfrontAttack.setSize(sf::Vector2f(0, 0));
	}

}

