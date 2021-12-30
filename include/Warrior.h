#pragma once

#include "DynamicObject.h"

class Warrior : public DynamicObject
{
public:
	Warrior(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~Warrior();

private:

};