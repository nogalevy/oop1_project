#pragma once
#include "StaticObject.h"


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
	/*
	Members:
	*/
};