#pragma once

#include "Player.h"
#include "Audio.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

class King : public Player
{
public:
	King(Icons symbol, const sf::Vector2f& position,  float objSize);
	~King();

	//virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;


	// Colisions:
	virtual void handleCollision(GameObject& ) override;
	
	virtual void handleCollision(King& ) override;
	virtual void handleCollision(Warrior& ) override;
	virtual void handleCollision(Mage& ) override;
	virtual void handleCollision(Thief& ) override;

	virtual void handleCollision(Fire& ) override;
	virtual void handleCollision(Gate& ) override;
	virtual void handleCollision(Key& /*gameObject*/) override {};
	virtual void handleCollision(Orc& ) override;
	virtual void handleCollision(Teleport& ) override;
	virtual void handleCollision(Throne& ) override;
	virtual void handleCollision(Wall& ) override;


	virtual void handleCollision(Dwarf& gameObject) override;
	virtual void handleCollision(Bonus& gameObject) override;

	bool isReachToThrone() const;

private:
	bool m_reachThrone;
};
