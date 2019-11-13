#include "Projectile.h"

Projectile::Projectile() {
	rect.setFillColor(sf::Color::Magenta);
	rect.setSize({50, 50});
}

void Projectile::update()
{
	if (direction == 1) {
		rect.move({ 0, -10.f });
	}
	else if (direction == 2) {
		rect.move({ 0, 10.f });
	}
	else if (direction == 3) {
		rect.move({ -10.f, 0.f });
	}
	else if (direction == 4) {
		rect.move({ 10.f, 0.f });
	}

	currentframe++;
}
