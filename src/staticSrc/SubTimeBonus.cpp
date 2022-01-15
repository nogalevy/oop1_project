#include "staticInclude/SubTimeBonus.h"

SubTimeBonus::SubTimeBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

//-----------------------------------------------------------------

void SubTimeBonus::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void SubTimeBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void SubTimeBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void SubTimeBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}
