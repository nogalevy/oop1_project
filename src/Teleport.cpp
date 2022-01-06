#include "Teleport.h"

Teleport::~Teleport()
{
}

void Teleport::handleCollision(GameObject& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Teleport::handleCollision(King& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window); //send more data? next position or somthing?
}

void Teleport::handleCollision(Warrior& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Teleport::handleCollision(Mage& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Teleport::handleCollision(Thief& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}
