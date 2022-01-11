#include "Mage.h"

Mage::Mage(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: Player(symbol, position, mapW, mapH)
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

void Mage::handleCollision(King& )
{
	
}

void Mage::handleCollision(Warrior& )
{
	
}

void Mage::handleCollision(Mage& )
{
	
}

void Mage::handleCollision(Thief& )
{
	
}

void Mage::handleCollision(Fire& )
{
}

void Mage::handleCollision(Gate& )
{
	moveToPrevPos();
}

void Mage::handleCollision(Key& )
{
	//nothing
}

void Mage::handleCollision(Orc& )
{
	moveToPrevPos();
}

void Mage::handleCollision(Teleport& )
{
	//nothing
}

void Mage::handleCollision(Throne& )
{
	moveToPrevPos();
}

void Mage::handleCollision(Wall& )
{
	moveToPrevPos();
}

void Mage::handleCollision(Dwarf& gameObject)
{
	moveToPrevPos();
}

