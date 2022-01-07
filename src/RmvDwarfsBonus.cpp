#include "RmvDwarfsBonus.h"

RmvDwarfsBonus::RmvDwarfsBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	:Bonus(symbol, position, mapW, mapH)
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
}

void RmvDwarfsBonus::handleCollision(Warrior& gameObject)
{
}

void RmvDwarfsBonus::handleCollision(Mage& gameObject)
{
}

void RmvDwarfsBonus::handleCollision(Thief& gameObject)
{
}