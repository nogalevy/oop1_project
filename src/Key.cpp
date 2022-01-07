#include "Key.h"

Key::~Key()
{
}

void Key::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

void Key::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Key::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
}

void Key::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
}

void Key::handleCollision(Thief& gameObject)
{
	m_isDisposed = true; //setIsDisposed ?
	gameObject.handleCollision(*this);
}

