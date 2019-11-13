#include "Enemy.h"
Enemy::Enemy()
{
	rect.setSize(sf::Vector2f(32, 53));
	rect.setPosition(200, 150);
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(-16.f, -13.f);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));


	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(-1.f);

}
void Enemy::updateCollision() {
	if (direction == 1) {
		rect.move({0, -1});
	}
	else if (direction == 2) {
		rect.move({ 0, 1 });
	}
	else if (direction == 3) {
		rect.move({ -1, 0 });
	}
	else if (direction == 4) {
		rect.move({ 1, 0 });
	}
	sprite.setPosition(rect.getPosition());
}