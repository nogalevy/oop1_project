#pragma once

#include "Bonus.h"

class RmvDwarfsBonus : public Bonus
{
public:
	RmvDwarfsBonus(Icons symbol, const sf::Vector2f& position,  float objSize);
	~RmvDwarfsBonus() = default;

	//Collisions:
	virtual void handleCollision(GameObject&) override {};

	//Moving Objects
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;
	virtual void handleCollision(Dwarf&) override {};

};