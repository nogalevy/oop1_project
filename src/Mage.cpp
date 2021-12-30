#include "Mage.h"

Mage::Mage(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: DynamicObject(icon, position, mapW, mapH)
{
}

Mage::~Mage()
{
}
