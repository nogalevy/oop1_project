#include "Teleport.h"

Teleport::~Teleport()
{
}

void Teleport::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this); //send more data? next position or somthing?
}

void Teleport::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

void Teleport::handleCollision(Dwarf& gameObject)
{
}
