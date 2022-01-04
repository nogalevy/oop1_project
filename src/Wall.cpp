#include "Wall.h"

/*
Wall::Wall(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: StaticObject(icon, position, mapW, mapH)
{
}
*/

Wall::~Wall()
{
}

void Wall::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
	std::cout << "in Wall. handle GameObject \n";
}

void Wall::handleCollision(King& gameObject)
{
	gameObject.handleCollision(*this); 
	std::cout << "in Wall. handle King \n";
}

void Wall::handleCollision(Warrior& gameObject)
{
	gameObject.handleCollision(*this);
	std::cout << "in Wall. handle Warrior \n";
}

void Wall::handleCollision(Mage& gameObject)
{
	gameObject.handleCollision(*this);
	std::cout << "in Wall. handle Mage \n";
}

void Wall::handleCollision(Thief& gameObject)
{
	gameObject.handleCollision(*this);
	std::cout << "in Wall. handle Thief \n";
}

