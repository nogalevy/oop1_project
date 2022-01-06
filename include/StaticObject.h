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
	~StaticObject() = default;

	//no meaning of colision with two static objects
	virtual void handleCollision(Fire&, Window& window) override {};
	virtual void handleCollision(Gate&, Window& window) override {};
	virtual void handleCollision(Key&, Window& window) override {};
	virtual void handleCollision(Orc&, Window& window) override {};
	virtual void handleCollision(Teleport&, Window& window) override {};
	virtual void handleCollision(Throne&, Window& window) override {};
	virtual void handleCollision(Wall&, Window& window) override {};
};