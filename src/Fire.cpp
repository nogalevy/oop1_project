#include "Fire.h"

Fire::~Fire()
{
}

void Fire::handleCollision(GameObject& gameObject, Window& window)
{
	gameObject.handleCollision(*this , window);
}
void Fire::handleCollision(King& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Fire::handleCollision(Warrior& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Fire::handleCollision(Mage& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Fire::handleCollision(Thief& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}
