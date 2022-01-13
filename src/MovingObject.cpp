#include "MovingObject.h"


MovingObject::MovingObject(Icons symbol, const sf::Vector2f& position,  float objSize)
	: GameObject(symbol, position,  objSize), m_location(position),m_prevPos(position)
{
}


void MovingObject::moveToPrevPos()
{
	getIcon().setPosition(m_prevPos);
}


