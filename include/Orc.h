#pragma once

#include "StaticObject.h"

class Orc : public StaticObject
{
public:
	using StaticObject::StaticObject;
	~Orc();


	//// Colisions:
	virtual void handleCollision(GameObject& gameObject) override;
	// make them one - dynamic type ? 
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	bool getIsDied() const;
	virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;
private:
	bool m_isDied =false;

};