#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(Icons symbol, const sf::Vector2f& position,  float objSize);
	virtual ~MovingObject() = default;

	void moveToPrevPos();

protected:
	sf::Vector2f& getPrevPos();
private:
	sf::Vector2f m_prevPos;
};