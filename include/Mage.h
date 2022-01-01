#pragma once

#include "DynamicObject.h"

class Mage : public DynamicObject
{
public:
	Mage(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~Mage();

	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;
private:

};