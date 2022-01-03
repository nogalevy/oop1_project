#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>

#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

class StaticObject : public GameObject
{
public:
	StaticObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~StaticObject();
};