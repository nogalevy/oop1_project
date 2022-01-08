#pragma once

#include "Bonus.h"

class AddTimeBonus : public Bonus
{
public:
	AddTimeBonus(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~AddTimeBonus();


	// Collisions:
	virtual void handleCollision(GameObject& gameObject) override;

	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	virtual void handleCollision(Dwarf& gameObject) override;


private:

};