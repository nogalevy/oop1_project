#include "staticInclude/StaticObject.h"

StaticObject::StaticObject(Icons symbol, const sf::Vector2f& position,  float objSize)
	: GameObject(symbol, position,  objSize), m_isDisposed(false)
{
}

bool StaticObject::isDisposed() const
{
	return m_isDisposed;
}

sf::Vector2f StaticObject::getPosition()
{
	return getIcon().getPosition();
}

void StaticObject::setIsDisposed(bool isDisposed)
{
	m_isDisposed = (isDisposed) ? true : false;
}

//StaticObject::~StaticObject()
//{
//}
