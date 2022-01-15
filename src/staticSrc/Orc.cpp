#include "staticInclude/Orc.h"

void Orc::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Orc::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Orc::handleCollision(Warrior& gameObject)
{
	setIsDisposed(true);
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Orc::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Orc::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

