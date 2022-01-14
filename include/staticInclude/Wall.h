#pragma once

#include "StaticObject.h"
//#include "Dwarf.h"
//#include "King.h"
//class King;

class Wall : public StaticObject
{
public:
	//Wall(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	using StaticObject::StaticObject;
	~Wall();


	//// Colisions:
	virtual void handleCollision(GameObject& gameObject) override;
	
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;

	virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;
private:

};