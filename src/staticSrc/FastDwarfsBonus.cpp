#include "staticInclude/FastDwarfsBonus.h"

FastDwarfsBonus::FastDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
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
	gameObject.handleCollision(*this);
	//m_isDisposed = true;
	setIsDisposed(true);
}

void FastDwarfsBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	//m_isDisposed = true;
	setIsDisposed(true);
}

void FastDwarfsBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	//m_isDisposed = true;
	setIsDisposed(true);
}

void FastDwarfsBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	//m_isDisposed = true;
	setIsDisposed(true);
}

void FastDwarfsBonus::handleCollision(Dwarf& gameObject)
{
}
