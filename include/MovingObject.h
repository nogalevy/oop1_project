#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~MovingObject() = default;

	void moveToPrevPos();
	//make it abstract

protected:
	sf::Vector2f m_location;
	sf::Vector2f m_prevPos;
};