#pragma once
#include "DynamicObject.h"

class Thief: public DynamicObject 
{
public:
	Thief(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~Thief();

	virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;


	//// Colisions:
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

	//virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;
private:
};
	/*
	bool m_hasKey;
	*/
	//bool m_hasKey;