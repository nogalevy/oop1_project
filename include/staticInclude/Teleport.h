#pragma once
#include "StaticObject.h"

//class Controller;

//NEED TO CHANGE TO INHERIT FROM STATIC CLASS
class Teleport : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Teleport();


	//sf::Vector2f getPosition()const;
	void setPartner(sf::Vector2f partner);

	//// Colisions:
	virtual void handleCollision(GameObject& gameObject) override;
	//
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;
private:
	/*
	Members:
	*/

	sf::Vector2f m_partner;
	
};