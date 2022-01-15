#pragma once

#include "StaticObject.h"

class Orc : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Orc() = default;

	//ColLisions:
	virtual void handleCollision(GameObject& gameObject) override;
	
	//Moving Objects
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;
	virtual void handleCollision(Dwarf&) override {};

};