#include "Mage.h"

Mage::Mage(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH)
{
}

Mage::~Mage()
{
}

//void Mage::move(sf::Vector2f direction, sf::Time deltaTime)
//{
//	auto speedPerSecond = 100.f;
//	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
//}

void Mage::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this));
}

void Mage::handleCollision(King& gameObject)
{

}

void Mage::handleCollision(Warrior& gameObject)
{
}

void Mage::handleCollision(Mage& gameObject)
{
}

void Mage::handleCollision(Thief& gameObject)
{
}

void Mage::handleCollision(Fire& gameObject)
{
}

void Mage::handleCollision(Gate& gameObject)
{
}

void Mage::handleCollision(Key& gameObject)
{
}

void Mage::handleCollision(Orc& gameObject)
{
}

void Mage::handleCollision(Teleport& gameObject)
{
}

void Mage::handleCollision(Throne& gameObject)
{
}

void Mage::handleCollision(Wall& gameObject)
{
	moveToPrevPos();
}

