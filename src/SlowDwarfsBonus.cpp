#include "SlowDwarfsBonus.h"

SlowDwarfsBonus::SlowDwarfsBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	:Bonus(symbol, position, mapW, mapH)
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
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Warrior& gameObject)
{
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Mage& gameObject)
{
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Thief& gameObject)
{
	m_isDisposed = true;
}

void SlowDwarfsBonus::handleCollision(Dwarf& gameObject)
{
}
