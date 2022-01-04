#include "Fire.h"

Fire::~Fire()
{
}

void Fire::handleCollision(GameObject& gameObject)
{
}
void Fire::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Fire::handleCollision(Warrior& gameObject)
{
}

void Fire::handleCollision(Mage& gameObject)
{
}

void Fire::handleCollision(Thief& gameObject)
{
}

void Fire::handleCollision(Fire& gameObject)
{
}

void Fire::handleCollision(Gate& gameObject)
{
}

void Fire::handleCollision(Key& gameObject)
{
}

void Fire::handleCollision(Orc& gameObject)
{
}

void Fire::handleCollision(Teleport& gameObject)
{
}

void Fire::handleCollision(Throne& gameObject)
{
}

void Fire::handleCollision(Wall& gameObject)
{
}
