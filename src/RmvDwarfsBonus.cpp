#include "RmvDwarfsBonus.h"

RmvDwarfsBonus::RmvDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

RmvDwarfsBonus::~RmvDwarfsBonus()
{
}


void RmvDwarfsBonus::handleCollision(GameObject& gameObject)
{
}

void RmvDwarfsBonus::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void RmvDwarfsBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void RmvDwarfsBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void RmvDwarfsBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void RmvDwarfsBonus::handleCollision(Dwarf& gameObject)
{
}
