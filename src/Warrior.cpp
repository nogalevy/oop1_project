#include "Warrior.h"



Warrior::Warrior(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: Player(symbol, position, mapW, mapH)
{
}

Warrior::~Warrior()
{
}


void Warrior::handleCollision(GameObject& gameObject)
{
	//if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this));
}

void Warrior::handleCollision(King& gameObject )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Warrior& gameObject )
{
	//nothing
}

void Warrior::handleCollision(Mage& gameObject )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Thief& gameObject )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Fire& gameObject )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Gate& gameObject )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Key& gameObject )
{
	//nothing
}

void Warrior::handleCollision(Orc& gameObject )
{
	//kills orc. orc drops key!!
	//killOrc();
}

void Warrior::handleCollision(Teleport& gameObject )
{
	//move to other teleport
	//teleportToNewPos(nextPos);
}

void Warrior::handleCollision(Throne& gameObject )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Wall& gameObject )
{
	moveToPrevPos();
}
