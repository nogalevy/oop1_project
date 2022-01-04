#include "Orc.h"

Orc::~Orc()
{
}

void Orc::handleCollision(GameObject& gameObject)
{
}
void Orc::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
}

void Orc::handleCollision(Warrior& gameObject)
{
}

void Orc::handleCollision(Mage& gameObject)
{
}

void Orc::handleCollision(Thief& gameObject)
{
}
