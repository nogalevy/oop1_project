#include "staticInclude/RmvDwarfsBonus.h"

RmvDwarfsBonus::RmvDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

//-----------------------------------------------------------------

void RmvDwarfsBonus::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void RmvDwarfsBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void RmvDwarfsBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void RmvDwarfsBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

