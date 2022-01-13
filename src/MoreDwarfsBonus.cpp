#include "MoreDwarfsBonus.h"

MoreDwarfsBonus::MoreDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

MoreDwarfsBonus::~MoreDwarfsBonus()
{
}


void MoreDwarfsBonus::handleCollision(GameObject& gameObject)
{
}

void MoreDwarfsBonus::handleCollision(King& gameObject)
{
	m_isDisposed = true;
}

void MoreDwarfsBonus::handleCollision(Warrior& gameObject)
{
	m_isDisposed = true;
}

void MoreDwarfsBonus::handleCollision(Mage& gameObject)
{
	m_isDisposed = true;
}

void MoreDwarfsBonus::handleCollision(Thief& gameObject)
{
	m_isDisposed = true;
}

void MoreDwarfsBonus::handleCollision(Dwarf& gameObject)
{
}
