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

void Warrior::handleCollision(King&  )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Warrior&  )
{
	//nothing
}

void Warrior::handleCollision(Mage&  )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Thief&  )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Fire&  )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Gate&  )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Key&  )
{
	//nothing
}

void Warrior::handleCollision(Orc&  )
{

	//kills orc. orc drops key!!
	//killOrc();
}

void Warrior::handleCollision(Teleport&  )
{
	//move to other teleport
	//teleportToNewPos(nextPos);
}

void Warrior::handleCollision(Throne&  )
{
	moveToPrevPos();
}

void Warrior::handleCollision(Wall&  )
{
	moveToPrevPos();
}
