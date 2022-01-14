#include "Mage.h"

Mage::Mage(Icons symbol, const sf::Vector2f& position,  float objSize)
	: Player(symbol, position,  objSize)
{
}

Mage::~Mage()
{
}


void Mage::handleCollision(GameObject& gameObject)
{
	//if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this));
}

void Mage::handleCollision(King& gameObject)
{
	gameObject.moveToPrevPos();
}

void Mage::handleCollision(Warrior& gameObject)
{
	gameObject.moveToPrevPos();
}

void Mage::handleCollision(Mage& )
{
	
}

void Mage::handleCollision(Thief& gameObject)
{
	gameObject.moveToPrevPos();
}

void Mage::handleCollision(Fire& )
{
}

void Mage::handleCollision(Gate& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

void Mage::handleCollision(Key& )
{
	//nothing
}

void Mage::handleCollision(Orc& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

void Mage::handleCollision(Teleport& )
{
	//nothing
}

void Mage::handleCollision(Throne& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

void Mage::handleCollision(Wall& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

void Mage::handleCollision(Dwarf& gameObject)
{
	moveToPrevPos();
}

void Mage::handleCollision(Bonus& gameObject)
{
	playSound(BONUS_COLISION);
}

