#include "AddTimeBonus.h"

AddTimeBonus::AddTimeBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	:Bonus(symbol, position, mapW, mapH)
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
