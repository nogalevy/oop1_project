#include "staticInclude/AddTimeBonus.h"

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
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}

void AddTimeBonus::handleCollision(Dwarf& gameObject)
{
}
