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

void Wall::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Wall::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Wall::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

void Wall::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

void Wall::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

void Wall::handleCollision(Dwarf& gameObject)
{
	gameObject.handleCollision(*this);
}

