#include "Gate.h"

Gate::~Gate()
{
}

void Gate::handleCollision(GameObject& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Gate::handleCollision(King& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Gate::handleCollision(Warrior& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Gate::handleCollision(Mage& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Gate::handleCollision(Thief& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}
