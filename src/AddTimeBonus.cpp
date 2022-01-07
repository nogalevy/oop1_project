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
}

void AddTimeBonus::handleCollision(Warrior& gameObject)
{
}

void AddTimeBonus::handleCollision(Mage& gameObject)
{
}

void AddTimeBonus::handleCollision(Thief& gameObject)
{
}

void AddTimeBonus::handleCollision(Dwarf& gameObject)
{
}
