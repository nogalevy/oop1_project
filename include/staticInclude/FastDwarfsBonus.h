#pragma once

#include "Bonus.h"

class FastDwarfsBonus : public Bonus
{
public:
	FastDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize);
	~FastDwarfsBonus();


	// Collisions:
	virtual void handleCollision(GameObject& gameObject) override;

	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	virtual void handleCollision(Dwarf& gameObject) override;


private:

};