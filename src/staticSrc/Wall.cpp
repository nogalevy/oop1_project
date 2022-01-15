#include "staticInclude/Wall.h"


void Wall::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Wall::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Wall::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Wall::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Wall::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Wall::handleCollision(Dwarf& gameObject)
{
	gameObject.handleCollision(*this);
}

