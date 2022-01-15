#pragma once
#include "MovingObject.h"

class Dwarf : public MovingObject 
{
public:
	Dwarf(Icons symbol, const sf::Vector2f& position,  float objSize);
	virtual ~Dwarf() = default;

	void move(sf::Time);

	// Colisions:
	virtual void handleCollision(GameObject& gameObject) override;

	//Moving Objects
	virtual void handleCollision(King& ) override {};
	virtual void handleCollision(Warrior& ) override {};
	virtual void handleCollision(Mage& ) override {};
	virtual void handleCollision(Thief& ) override {};
	virtual void handleCollision(Dwarf& ) override {};

	//Static Objects
	virtual void handleCollision(Fire& ) override {};
	virtual void handleCollision(Gate& ) override {};
	virtual void handleCollision(Key& ) override {};
	virtual void handleCollision(Orc& ) override {};
	virtual void handleCollision(Teleport& ) override {};
	virtual void handleCollision(Throne& ) override {};
	virtual void handleCollision(Wall& ) override;
	virtual void handleCollision(Bonus& ) override {};

	//Speed Adjustments Functions
	void increaseSpeed();
	void decreaseSpeed();
private:
	sf::Vector2f m_direction;
	float m_speedPerSecond; 
};