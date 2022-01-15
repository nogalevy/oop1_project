#pragma once

#include "StaticObject.h"

class Fire : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Fire() = default;

	// Collisions:
	virtual void handleCollision(GameObject& gameObject) override;
	
	//Moving Objects
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& ) override;
	virtual void handleCollision(Thief& gameObject) override;
	virtual void handleCollision(Dwarf&) override {};

};