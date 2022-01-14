#include "SlowDwarfsBonus.h"

SlowDwarfsBonus::SlowDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

SlowDwarfsBonus::~SlowDwarfsBonus()
{
}


void SlowDwarfsBonus::handleCollision(GameObject& gameObject)
{
}

void SlowDwarfsBonus::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Dwarf& gameObject)
{
}
