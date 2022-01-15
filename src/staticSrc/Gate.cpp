#include "staticInclude/Gate.h"


void Gate::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Gate::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Gate::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Gate::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

//-----------------------------------------------------------------

void Gate::handleCollision(Thief& gameObject)
{
	if (gameObject.getHasKey())
	{
		setIsDisposed(true);
		gameObject.setHasKey(false);
	}
	gameObject.handleCollision(*this);
}

