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
