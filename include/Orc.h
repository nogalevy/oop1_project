#pragma once

#include "StaticObject.h"

class Orc : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Orc();


	//// Colisions:
	virtual void handleCollision(GameObject& gameObject, Window& window) override;
	// make them one - dynamic type ? 
	virtual void handleCollision(King& gameObject, Window& window) override;
	virtual void handleCollision(Warrior& gameObject, Window& window) override;
	virtual void handleCollision(Mage& gameObject, Window& window) override;
	virtual void handleCollision(Thief& gameObject, Window& window) override;

	//virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;
private:

};