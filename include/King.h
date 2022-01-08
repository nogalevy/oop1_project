#pragma once

#include "Player.h"
#include "Audio.h"

class King : public Player
{
public:
	King(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~King();

	//virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;


	// Colisions:
	virtual void handleCollision(GameObject& ) override;
	// make them one - dynamic type ? 
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

	bool isReachToThrone() const;
	//virtual void handleCollision(Bonus& gameObject) override;

private:
	Audio m_colisionSound;
	bool m_reachThrone;
};
