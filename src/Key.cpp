#include "Key.h"

Key::~Key()
{
}

void Key::handleCollision(GameObject& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Key::handleCollision(King& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Key::handleCollision(Warrior& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Key::handleCollision(Mage& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Key::handleCollision(Thief& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

