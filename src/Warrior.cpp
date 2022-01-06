#include "Warrior.h"



Warrior::Warrior(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: Player(symbol, position, mapW, mapH)
{
}

Warrior::~Warrior()
{
}


void Warrior::handleCollision(GameObject& gameObject, Window& window)
{
	//if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this), window);
}

void Warrior::handleCollision(King& gameObject, Window& window)
{
	moveToPrevPos();
}

void Warrior::handleCollision(Warrior& gameObject, Window& window)
{
	//nothing
}

void Warrior::handleCollision(Mage& gameObject, Window& window)
{
	moveToPrevPos();
}

void Warrior::handleCollision(Thief& gameObject, Window& window)
{
	moveToPrevPos();
}

void Warrior::handleCollision(Fire& gameObject, Window& window)
{
	moveToPrevPos();
}

void Warrior::handleCollision(Gate& gameObject, Window& window)
{
	moveToPrevPos();
}

void Warrior::handleCollision(Key& gameObject, Window& window)
{
	//nothing
}

void Warrior::handleCollision(Orc& gameObject, Window& window)
{
	//kills orc. orc drops key!!
	//killOrc();
}

void Warrior::handleCollision(Teleport& gameObject, Window& window)
{
	//move to other teleport
	//teleportToNewPos(nextPos);
}

void Warrior::handleCollision(Throne& gameObject, Window& window)
{
	moveToPrevPos();
}

void Warrior::handleCollision(Wall& gameObject, Window& window)
{
	moveToPrevPos();
}
