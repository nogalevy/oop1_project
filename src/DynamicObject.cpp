#include "..\include\DynamicObject.h"
#include "DynamicObject.h"


DynamicObject::DynamicObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position, mapW, mapH), m_location(position)
	//,m_prevPos(position)
{
}

DynamicObject::~DynamicObject()
{
}


void DynamicObject::move(sf::Vector2f direction, sf::Time deltaTime)
{
	auto speedPerSecond = 100.f;
	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
}
