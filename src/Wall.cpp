#include "Wall.h"

/*
Wall::Wall(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: StaticObject(icon, position, mapW, mapH)
{
}
*/

Wall::~Wall()
{
}

void Wall::handleCollision(GameObject& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Wall::handleCollision(King& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Wall::handleCollision(Warrior& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Wall::handleCollision(Mage& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

void Wall::handleCollision(Thief& gameObject, Window& window)
{
	gameObject.handleCollision(*this, window);
}

