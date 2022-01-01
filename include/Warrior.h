#pragma once

#include "DynamicObject.h"

class Warrior : public DynamicObject
{
public:
	Warrior(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~Warrior();

	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;
private:

};