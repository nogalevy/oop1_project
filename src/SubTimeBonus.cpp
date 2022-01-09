#include "SubTimeBonus.h"

SubTimeBonus::SubTimeBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	:Bonus(symbol, position, mapW, mapH)
{
}

SubTimeBonus::~SubTimeBonus()
{
}


void SubTimeBonus::handleCollision(GameObject& gameObject)
{
}

void SubTimeBonus::handleCollision(King& gameObject)
{
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Warrior& gameObject)
{
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Mage& gameObject)
{
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Thief& gameObject)
{
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Dwarf& gameObject)
{
}
