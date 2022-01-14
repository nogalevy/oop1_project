#pragma once

#include "StaticObject.h"

class Fire : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Fire();

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

};