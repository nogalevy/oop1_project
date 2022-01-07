#include "Fire.h"

Fire::~Fire()
{
}

void Fire::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this );
}
void Fire::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Fire::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

void Fire::handleCollision(Mage& gameObject)
{
	m_isDisposed = true;
	//gameObject.handleCollision(*this);
}

void Fire::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
}

void Fire::handleCollision(Dwarf& gameObject)
{
}
