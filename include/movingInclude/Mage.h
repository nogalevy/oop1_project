#pragma once

#include "Player.h"
#include "King.h"
#include "Warrior.h"
#include "Thief.h"


class Mage : public Player
{
public:
	Mage(Icons symbol, const sf::Vector2f& position,  float objSize);
	~Mage() = default;

	// Colisions:
	virtual void handleCollision(GameObject& ) override;
	
	//Moving Objects
	virtual void handleCollision(King& ) override;
	virtual void handleCollision(Warrior& ) override;
	virtual void handleCollision(Mage&) override {};
	virtual void handleCollision(Thief& ) override;
	virtual void handleCollision(Dwarf& ) override;

	//Static Object
	virtual void handleCollision(Fire&) override;
	virtual void handleCollision(Gate& ) override;
	virtual void handleCollision(Key&) override {};
	virtual void handleCollision(Orc& ) override;
	virtual void handleCollision(Teleport&) override {};
	virtual void handleCollision(Throne& ) override;
	virtual void handleCollision(Wall& ) override;
	virtual void handleCollision(Bonus& ) override;
};