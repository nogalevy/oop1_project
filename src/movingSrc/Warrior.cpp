#include "movingInclude/Warrior.h"

Warrior::Warrior(Icons symbol, const sf::Vector2f& position,  float objSize)
	: Player(symbol, position,  objSize)
{
}

//-----------------------------------------------------------------

void Warrior::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*(this));
}

//-----------------------------------------------------------------

void Warrior::handleCollision(King& gameObject)
{
	gameObject.moveToPrevPos(); 
}

//-----------------------------------------------------------------

void Warrior::handleCollision(Mage& gameObject)
{
	gameObject.moveToPrevPos();

}

//-----------------------------------------------------------------

void Warrior::handleCollision(Thief& gameObject)
{
	gameObject.moveToPrevPos();

}

//-----------------------------------------------------------------

void Warrior::handleCollision(Dwarf& )
{
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Warrior::handleCollision(Fire&  )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Warrior::handleCollision(Gate&  )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

void Warrior::handleCollision(Teleport&  )
{
	playSound(TELEPORT_COLISION);
}

void Warrior::handleCollision(Throne&  )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Warrior::handleCollision(Wall&  )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Warrior::handleCollision(Bonus& gameObject)
{
	playSound(BONUS_COLISION);
}
