#include "Enemy.h"
Enemy::Enemy()
{
	rect.setSize(sf::Vector2f(27, 53));
	rect.setPosition(200, 150);
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(-16.f, -13.f);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));


	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Green);
	rect.setOutlineThickness(-1.f);

}
void Enemy::updateCollision() {
	if (direction == 1) {
		if (canMoveUp == true)
		{
			rect.move({ 0, -1 });
			sprite.setTextureRect(sf::IntRect(64 * (int)animationFrameWalk, 64 * 8, 64, 64));
			//direction = 1;

			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;

		}


	}

	if (direction == 2) {
		if (canMoveDown == true)
		{
			rect.move({ 0, 1 });
			sprite.setTextureRect(sf::IntRect(64 * (int)animationFrameWalk, 64 * 10, 64, 64));
			//direction = 2;

			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;

		}
	}

	if (direction == 3) {
		if (canMoveLeft == true)
		{
			rect.move({ -1, 0 });
			sprite.setTextureRect(sf::IntRect(64 * (int)animationFrameWalk, 64 * 9, 64, 64));
		//	direction = 3;

			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;

		}
	}


	if (direction == 4) {
		if (canMoveRight) {
			rect.move({ 1, 0 });

			sprite.setTextureRect(sf::IntRect(64 * (int)animationFrameWalk, 64 * 11, 64, 64));
		//	direction = 4;

			canMoveUp = true;
			canMoveDown = true;
			canMoveLeft = true;
			canMoveRight = true;
		}
		
	}

	animationFrameWalk += 0.2;
	if (animationFrameWalk >= 8) {
		animationFrameWalk = 0;
	}

	sprite.setPosition(rect.getPosition());
}