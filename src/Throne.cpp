#include "Throne.h"

Throne::~Throne()
{
}

void Throne::handleCollision(GameObject& gameObject)
{
}

void Throne::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Throne::handleCollision(Warrior& gameObject)
{
}

void Throne::handleCollision(Mage& gameObject)
{
}

void Throne::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}
