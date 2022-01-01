#include "King.h"

King::King(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: DynamicObject(symbol, position, mapW, mapH)
{
}

King::~King()
{
}

void King::move(/*sf::Time&*/)
{
}
