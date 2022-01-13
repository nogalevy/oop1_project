#include "FastDwarfsBonus.h"

FastDwarfsBonus::FastDwarfsBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	:Bonus(symbol, position, mapW, mapH)
{
}

FastDwarfsBonus::~FastDwarfsBonus()
{
}


void FastDwarfsBonus::handleCollision(GameObject& gameObject)
{
}

void FastDwarfsBonus::handleCollision(King& gameObject)
{
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Warrior& gameObject)
{
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Mage& gameObject)
{
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Thief& gameObject)
{
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Dwarf& gameObject)
{
}
