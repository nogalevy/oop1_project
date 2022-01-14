#include "Warrior.h"



Warrior::Warrior(Icons symbol, const sf::Vector2f& position,  float objSize)
	: Player(symbol, position,  objSize)
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

void Warrior::handleCollision(King& gameObject)
{
	//If we want for the characters not to go over eachother this works:
	// (have to include "king.h")
	gameObject.moveToPrevPos(); 
}

void Warrior::handleCollision(Warrior& gameObject)
{
	//nothing
	//gameObject.moveToPrevPos();
}

void Warrior::handleCollision(Mage& gameObject)
{
	gameObject.moveToPrevPos();

}

void Warrior::handleCollision(Thief& gameObject)
{
	gameObject.moveToPrevPos();

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

void Warrior::handleCollision(Dwarf& gameObject)
{
	moveToPrevPos();
}
