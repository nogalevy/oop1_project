#include "Fire.h"

Fire::~Fire()
{
}

void Fire::handleCollision(GameObject& gameObject)
{
}
void Fire::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Fire::handleCollision(Warrior& gameObject)
{
}

void Fire::handleCollision(Mage& gameObject)
{
}

void Fire::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}
