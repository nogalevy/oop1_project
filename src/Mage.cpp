#include "Mage.h"

Mage::Mage(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: Player(symbol, position, mapW, mapH)
{
}

Mage::~Mage()
{
}


void Mage::handleCollision(GameObject& gameObject, Window& window)
{
	//if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this), window);
}

void Mage::handleCollision(King& gameObject, Window& window)
{
	moveToPrevPos();
}

void Mage::handleCollision(Warrior& gameObject, Window& window)
{
	moveToPrevPos();
}

void Mage::handleCollision(Mage& gameObject, Window& window)
{
	//nothing
}

void Mage::handleCollision(Thief& gameObject, Window& window)
{
	moveToPrevPos();
}

void Mage::handleCollision(Fire& gameObject, Window& window)
{
	//puts out fire
	//putOutFire();
}

void Mage::handleCollision(Gate& gameObject, Window& window)
{
	moveToPrevPos();
}

void Mage::handleCollision(Key& gameObject, Window& window)
{
	//nothing
}

void Mage::handleCollision(Orc& gameObject, Window& window)
{
	moveToPrevPos();
}

void Mage::handleCollision(Teleport& gameObject, Window& window)
{
	//nothing
}

void Mage::handleCollision(Throne& gameObject, Window& window)
{
	moveToPrevPos();
}

void Mage::handleCollision(Wall& gameObject, Window& window)
{
	moveToPrevPos();
}

