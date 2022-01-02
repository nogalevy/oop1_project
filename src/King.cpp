#include "King.h"

King::King(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: DynamicObject(symbol, position, mapW, mapH)
{
}

King::~King()
{
}

void King::move(sf::Vector2f direction, sf::Time deltaTime)
{
	auto speedPerSecond = 100.f;
	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
}

void King::handleCollision(GameObject& gameObject)
{
	//if (&gameObject == this) return;
	////double dispatch
	//gameObject.handleCollision(*this);
}

void King::handleCollision(King& gameObject)
{
	//ignore ?
}

void King::handleCollision(Warrior& gameObject)
{
}

void King::handleCollision(Mage& gameObject)
{
}

void King::handleCollision(Thief& gameObject)
{
}

void King::handleCollision(Fire& gameObject)
{
	// not allowed to move
}

void King::handleCollision(Gate& gameObject)
{
	//no
}

void King::handleCollision(Key& gameObject)
{
	// no?
}

void King::handleCollision(Orc& gameObject)
{
	//no ?
}

void King::handleCollision(Teleport& gameObject)
{
	//move to other teleport
}

void King::handleCollision(Throne& gameObject)
{
	//step on it and end level
}

void King::handleCollision(Wall& gameObject)
{
	//no
}
