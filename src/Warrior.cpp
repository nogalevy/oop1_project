#include "Warrior.h"



Warrior::Warrior(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH)
{
}

Warrior::~Warrior()
{
}

//void Warrior::move(sf::Vector2f direction, sf::Time deltaTime)
//{
//	auto speedPerSecond = 100.f;
//	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
//}

void Warrior::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*(this));
}

void Warrior::handleCollision(King& gameObject)
{
}

void Warrior::handleCollision(Warrior& gameObject)
{
}

void Warrior::handleCollision(Mage& gameObject)
{
}

void Warrior::handleCollision(Thief& gameObject)
{
}

void Warrior::handleCollision(Fire& gameObject)
{
}

void Warrior::handleCollision(Gate& gameObject)
{
}

void Warrior::handleCollision(Key& gameObject)
{
}

void Warrior::handleCollision(Orc& gameObject)
{
}

void Warrior::handleCollision(Teleport& gameObject)
{
}

void Warrior::handleCollision(Throne& gameObject)
{
}

void Warrior::handleCollision(Wall& gameObject)
{
	moveToPrevPos();
}
