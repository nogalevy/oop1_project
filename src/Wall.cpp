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
}

void Wall::handleCollision(King& gameObject)
{
}

void Wall::handleCollision(Warrior& gameObject)
{
}



void Wall::handleCollision(Mage& gameObject)
{
}

void Wall::handleCollision(Thief& gameObject)
{
}

void Wall::handleCollision(Fire& gameObject)
{
}

void Wall::handleCollision(Gate& gameObject)
{
}

void Wall::handleCollision(Key& gameObject)
{
}

void Wall::handleCollision(Orc& gameObject)
{
}

void Wall::handleCollision(Teleport& gameObject)
{
}

void Wall::handleCollision(Throne& gameObject)
{
}

void Wall::handleCollision(Wall& gameObject)
{
}
