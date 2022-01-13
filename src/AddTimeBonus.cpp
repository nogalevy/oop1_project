#include "AddTimeBonus.h"

AddTimeBonus::AddTimeBonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	:Bonus(symbol, position,  objSize)
{
}

AddTimeBonus::~AddTimeBonus()
{
}


void AddTimeBonus::handleCollision(GameObject& gameObject)
{
}

void AddTimeBonus::handleCollision(King& gameObject)
{
	playAudio();
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Warrior& gameObject)
{
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Mage& gameObject)
{
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Thief& gameObject)
{
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Dwarf& gameObject)
{
}
