#include "staticInclude/Gate.h"

Gate::~Gate()
{
}

void Gate::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Gate::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Gate::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

void Gate::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

void Gate::handleCollision(Thief& gameObject)
{
	if (gameObject.getHasKey())
	{
		m_isDisposed = true;
		gameObject.setHasKey(false);
	}
	gameObject.handleCollision(*this);
}

void Gate::handleCollision(Dwarf& gameObject)
{
}
