#pragma once
#include "DynamicObject.h"

class Thief: public DynamicObject 
{
public:
	Thief(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~Thief();

	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;

private:
};
	/*
	bool m_hasKey;
	*/
	//bool m_hasKey;