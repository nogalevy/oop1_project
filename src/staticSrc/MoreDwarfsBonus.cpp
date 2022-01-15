#include "staticInclude/MoreDwarfsBonus.h"

MoreDwarfsBonus::MoreDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

//-----------------------------------------------------------------

void MoreDwarfsBonus::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void MoreDwarfsBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void MoreDwarfsBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void MoreDwarfsBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}
