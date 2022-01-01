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
