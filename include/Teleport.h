#pragma once
#include "StaticObject.h"

//class Window;

//NEED TO CHANGE TO INHERIT FROM STATIC CLASS
class Teleport : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Teleport();


	//// Colisions:
	virtual void handleCollision(GameObject& gameObject) override;
	//// make them one - dynamic type ? 
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	//virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;
private:
	/*
	Members:
	*/
};