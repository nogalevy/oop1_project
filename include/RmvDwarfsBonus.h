#pragma once

#include "Bonus.h"

class RmvDwarfsBonus : public Bonus
{
public:
	RmvDwarfsBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~RmvDwarfsBonus();


	// Collisions:
	virtual void handleCollision(GameObject& gameObject) override;

	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;


private:

};