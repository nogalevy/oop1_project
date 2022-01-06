#pragma once

#include "StaticObject.h"

class Throne : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Throne();


	// Colisions:
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