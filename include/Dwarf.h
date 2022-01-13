#pragma once
#include "MovingObject.h"

class Dwarf : public MovingObject 
{
public:
	Dwarf(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~Dwarf();

	void move(sf::Time);

	// Colisions:
	virtual void handleCollision(GameObject& gameObject) override;
	// make them one - dynamic type ? 
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	virtual void handleCollision(Fire& gameObject) override;
	virtual void handleCollision(Gate& gameObject) override;
	virtual void handleCollision(Key& gameObject) override;
	virtual void handleCollision(Orc& gameObject) override;
	virtual void handleCollision(Teleport& gameObject) override;
	virtual void handleCollision(Throne& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;

	virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;

	void increaseSpeed();
	void decreaseSpeed();
private:
	sf::Vector2f m_direction;
	float m_speedPerSecond = 100.f;
};