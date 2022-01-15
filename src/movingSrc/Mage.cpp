#include "movingInclude/Mage.h"

Mage::Mage(Icons symbol, const sf::Vector2f& position,  float objSize)
	: Player(symbol, position,  objSize)
{
}

//-----------------------------------------------------------------

void Mage::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*(this));
}

//-----------------------------------------------------------------

void Mage::handleCollision(King& gameObject)
{
	gameObject.moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Warrior& gameObject)
{
	gameObject.moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Thief& gameObject)
{
	gameObject.moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Dwarf& )
{
	playSound(DWARF_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Fire&)
{
	playSound(MAGE_FIRE_COLISION);
}

void Mage::handleCollision(Gate& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Orc& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Throne& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Wall& )
{
	playSound(DEFAULT_COLISION);
	moveToPrevPos();
}

//-----------------------------------------------------------------

void Mage::handleCollision(Bonus& )
{
	playSound(BONUS_COLISION);
}

