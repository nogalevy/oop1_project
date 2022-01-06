#include "MovingObject.h"


MovingObject::MovingObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position, mapW, mapH), m_location(position)
	,m_prevPos(position)
{
}

//MovingObject::~MovingObject()
//{
//}


//void MovingObject::move(sf::Vector2f direction, sf::Time deltaTime)
//{
//	m_prevPos = m_icon.getPosition();
//	auto speedPerSecond = 100.f;
//	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
//}

void MovingObject::moveToPrevPos()
{
	m_icon.setPosition(m_prevPos);
}
