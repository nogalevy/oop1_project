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
	gameObject.handleCollision(*this); //added #include king in Wall (???)
	//gameObject.handleCollision(*this); // LAMA ZE LO OVED???????????????????
	std::cout << "in Wall. handle King \n";
}

void Wall::handleCollision(Warrior& gameObject)
{
	std::cout << "in Wall. handle Warrior \n";
}

void Wall::handleCollision(Mage& gameObject)
{
	std::cout << "in Wall. handle Mage \n";
}

void Wall::handleCollision(Thief& gameObject)
{
	std::cout << "in Wall. handle Thief \n";
}

void Wall::handleCollision(Fire& gameObject)
{
	std::cout << "in Wall. handle Fire \n";
}

void Wall::handleCollision(Gate& gameObject)
{
	std::cout << "in Wall. handle Gate \n";
}

void Wall::handleCollision(Key& gameObject)
{
	std::cout << "in Wall. handle Key \n";
}

void Wall::handleCollision(Orc& gameObject)
{
	std::cout << "in Wall. handle Orc \n";
}

void Wall::handleCollision(Teleport& gameObject)
{
	std::cout << "in Wall. handle Teleport \n";
}

void Wall::handleCollision(Throne& gameObject)
{
	std::cout << "in Wall. handle Throne \n";
}

void Wall::handleCollision(Wall& gameObject)
{
	std::cout << "in Wall. handle Wall \n";
}
