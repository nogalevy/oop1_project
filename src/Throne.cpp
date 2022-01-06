#include "Throne.h"

Throne::~Throne()
{
}

void Throne::handleCollision(GameObject& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Throne::handleCollision(King& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Throne::handleCollision(Warrior& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Throne::handleCollision(Mage& gameObject, Window& window)
{
	gameObject.handleCollision(*this , window);
}

void Throne::handleCollision(Thief& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}
