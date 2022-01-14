#include "SubTimeBonus.h"

SubTimeBonus::SubTimeBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
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
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void SubTimeBonus::handleCollision(Dwarf& gameObject)
{
}
