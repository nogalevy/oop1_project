#include "Throne.h"

Throne::~Throne()
{
}

void Throne::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Throne::handleCollision(King& gameObject)
{
	gameObject.setPosition(getIcon().getPosition());
	gameObject.handleCollision(*this);
}

void Throne::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

void Throne::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this );
}

void Throne::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

void Throne::handleCollision(Dwarf& gameObject)
{
}
