#pragma once
#include "StaticObject.h"

class Teleport : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Teleport() = default;

	void setPartner(sf::Vector2f partner);

	//Collisions
	virtual void handleCollision(GameObject& gameObject) override;
	
	//Moving Objects
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;
	virtual void handleCollision(Dwarf&) override {};

private:
	sf::Vector2f m_partner;	//Partner Teleport's Location
};