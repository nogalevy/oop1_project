#pragma once

#include "GameObject.h"
#include <SFML/Graphics.hpp>

#include "movingInclude/King.h"
#include "movingInclude/Mage.h"
#include "movingInclude/Warrior.h"
#include "movingInclude/Thief.h"
#include "movingInclude/Dwarf.h"


class StaticObject : public GameObject
{
public:
	StaticObject(Icons symbol, const sf::Vector2f& position,  float objSize);
	~StaticObject() = default;

	//No meaning to two static objects colliding
	virtual void handleCollision(Fire&) override {};
	virtual void handleCollision(Gate&) override {};
	virtual void handleCollision(Key&) override {};
	virtual void handleCollision(Orc&) override {};
	virtual void handleCollision(Teleport&) override {};
	virtual void handleCollision(Throne&) override {};
	virtual void handleCollision(Wall&) override {};
	virtual void handleCollision(Bonus&) override {};

	bool isDisposed() const;
	sf::Vector2f getPosition();

protected:
	void setIsDisposed(bool isDisposed);

private:
	bool m_isDisposed; 
};