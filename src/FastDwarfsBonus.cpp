#include "FastDwarfsBonus.h"

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
	playAudio();
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Warrior& gameObject)
{
	playAudio();
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Mage& gameObject)
{
	playAudio();
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Thief& gameObject)
{
	playAudio();
	m_isDisposed = true;
}

void FastDwarfsBonus::handleCollision(Dwarf& gameObject)
{
}
