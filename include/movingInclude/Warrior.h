#pragma once

#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Thief.h"


class Warrior : public Player
{
public:
	Warrior(Icons symbol, const sf::Vector2f& position,  float objSize);
	~Warrior() = default;

	// Colisions:
	virtual void handleCollision(GameObject& ) override;
	
	//Moving Objects
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior&) override {};
	virtual void handleCollision(Mage& ) override;
	virtual void handleCollision(Thief& ) override;
	virtual void handleCollision(Dwarf& ) override;

	//Static Objects
	virtual void handleCollision(Fire& ) override;
	virtual void handleCollision(Gate& ) override;
	virtual void handleCollision(Key&) override {};
	virtual void handleCollision(Orc&) override {};
	virtual void handleCollision(Teleport&) override;
	virtual void handleCollision(Throne& ) override;
	virtual void handleCollision(Wall& ) override;
	virtual void handleCollision(Bonus& gameObject) override;

};