#include "Gate.h"

Gate::~Gate()
{
}

void Gate::handleCollision(GameObject& gameObject)
{
}

void Gate::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Gate::handleCollision(Warrior& gameObject)
{
}

void Gate::handleCollision(Mage& gameObject)
{
}

void Gate::handleCollision(Thief& gameObject)
{
}
