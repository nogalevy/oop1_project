#include "Thief.h"

Thief::Thief(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: DynamicObject(symbol, position, mapW, mapH)
{
}

Thief::~Thief()
{
}

void Thief::move(sf::Vector2f direction, sf::Time deltaTime)
{
	auto speedPerSecond = 100.f;
	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
}

void Thief::handleCollision(GameObject& gameObject)
{
}

void Thief::handleCollision(King& gameObject)
{
}

void Thief::handleCollision(Warrior& gameObject)
{
}

void Thief::handleCollision(Mage& gameObject)
{
}

void Thief::handleCollision(Thief& gameObject)
{
}

void Thief::handleCollision(Fire& gameObject)
{
}

void Thief::handleCollision(Gate& gameObject)
{
}

void Thief::handleCollision(Key& gameObject)
{
}

void Thief::handleCollision(Orc& gameObject)
{
}

void Thief::handleCollision(Teleport& gameObject)
{
}

void Thief::handleCollision(Throne& gameObject)
{
}

void Thief::handleCollision(Wall& gameObject)
{
}
