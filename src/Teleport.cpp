#include "Teleport.h"

Teleport::~Teleport()
{
}

void Teleport::handleCollision(GameObject& gameObject)
{
}

void Teleport::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this); //send more data? next position or somthing?
}

void Teleport::handleCollision(Warrior& gameObject)
{
}

void Teleport::handleCollision(Mage& gameObject)
{
}

void Teleport::handleCollision(Thief& gameObject)
{
}
