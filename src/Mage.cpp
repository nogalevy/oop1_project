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

void Mage::handleCollision(King& gameObject)
{
	moveToPrevPos();
}

void Mage::handleCollision(Warrior& gameObject)
{
	moveToPrevPos();
}

void Mage::handleCollision(Mage& gameObject)
{
	//nothing
}

void Mage::handleCollision(Thief& gameObject)
{
	moveToPrevPos();
}

void Mage::handleCollision(Fire& gameObject)
{

	//puts out fire
	//putOutFire();
}

void Mage::handleCollision(Gate& gameObject)
{
	moveToPrevPos();
}

void Mage::handleCollision(Key& gameObject)
{
	//nothing
}

void Mage::handleCollision(Orc& gameObject)
{
	moveToPrevPos();
}

void Mage::handleCollision(Teleport& gameObject)
{
	//nothing
}

void Mage::handleCollision(Throne& gameObject)
{
	moveToPrevPos();
}

void Mage::handleCollision(Wall& gameObject)
{
	moveToPrevPos();
}

