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
}

void SubTimeBonus::handleCollision(Warrior& gameObject)
{
}

void SubTimeBonus::handleCollision(Mage& gameObject)
{
}

void SubTimeBonus::handleCollision(Thief& gameObject)
{
}