#pragma once

#include "StaticObject.h"

class Bonus : public StaticObject
{
public:
	Bonus(Icons symbol, const sf::Vector2f& position,  float objSize);
	~Bonus();

};