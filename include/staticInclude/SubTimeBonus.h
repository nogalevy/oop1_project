#pragma once

#include "Bonus.h"

class SubTimeBonus : public Bonus
{
public:
	SubTimeBonus(Icons symbol, const sf::Vector2f& position,  float objSize);
	~SubTimeBonus();


	// Collisions:
	virtual void handleCollision(GameObject& gameObject) override;

	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	virtual void handleCollision(Dwarf& gameObject) override;


private:

};