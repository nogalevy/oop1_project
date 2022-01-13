#include "MoreDwarfsBonus.h"

MoreDwarfsBonus::MoreDwarfsBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	:Bonus(symbol, position, mapW, mapH)
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
