#pragma once

#include "StaticObject.h"
//#include "King.h"
//class King;

class Wall : public StaticObject
{
public:
	//Wall(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	using StaticObject::StaticObject;
	~Wall();


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