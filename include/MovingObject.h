#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~MovingObject() = default;

	//TODO: put move functions in king mage etc
	void move(sf::Vector2f direction, sf::Time deltaTime);// = 0;

	void moveToPrevPos();
	
	//make it abstract

protected:


	/*
	bool m_inBoard; //??
	bool m_canStep; //??
	*/

	sf::Vector2f m_location;
	sf::Vector2f m_prevPos;
	//sf::Vector2f m_prevPos;
	//sf::Vector2f m_direction;
};