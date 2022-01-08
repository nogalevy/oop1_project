#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>

#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"


class StaticObject : public GameObject
{
public:
	StaticObject(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~StaticObject() = default;

	//no meaning of colision with two static objects
	virtual void handleCollision(Fire&) override {};
	virtual void handleCollision(Gate&) override {};
	virtual void handleCollision(Key&) override {};
	virtual void handleCollision(Orc&) override {};
	virtual void handleCollision(Teleport&) override {};
	virtual void handleCollision(Throne&) override {};
	virtual void handleCollision(Wall&) override {};

	bool isDisposed() const;
	sf::Vector2f getPosition()const;

protected:
	bool m_isDisposed;
};