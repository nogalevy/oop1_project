#include "StaticObject.h"

StaticObject::StaticObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: GameObject(symbol, position, mapW, mapH), m_isDisposed(false)
{
}

bool StaticObject::isDisposed() const
{
	return m_isDisposed;
}

//StaticObject::~StaticObject()
//{
//}
