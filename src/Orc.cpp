#include "Orc.h"

Orc::~Orc()
{
}

void Orc::handleCollision(GameObject& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}
void Orc::handleCollision(King& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Orc::handleCollision(Warrior& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Orc::handleCollision(Mage& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Orc::handleCollision(Thief& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}
