#include "MovingObject.h"


MovingObject::MovingObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position, mapW, mapH), m_location(position),m_prevPos(position)
{
}


void MovingObject::moveToPrevPos()
{
	getIcon().setPosition(m_prevPos);
}


