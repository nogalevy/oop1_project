#include "staticInclude/SlowDwarfsBonus.h"

SlowDwarfsBonus::SlowDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

//-----------------------------------------------------------------

void SlowDwarfsBonus::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void SlowDwarfsBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void SlowDwarfsBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

//-----------------------------------------------------------------

void SlowDwarfsBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	setIsDisposed(true);
}

