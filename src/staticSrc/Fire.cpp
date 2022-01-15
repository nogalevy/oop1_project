#include "staticInclude/Fire.h"


void Fire::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this );
}

//-----------------------------------------------------------------

void Fire::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Fire::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Fire::handleCollision(Mage& )
{
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void Fire::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

