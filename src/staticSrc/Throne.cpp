#include "staticInclude/Throne.h"


void Throne::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Throne::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Throne::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Throne::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this );
}

//-----------------------------------------------------------------

void Throne::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

