#pragma once

#include "Player.h"
//class Window;

class Warrior : public Player
{
public:
	Warrior(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~Warrior();

	//virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;


	//// Colisions:
	virtual void handleCollision(GameObject& gameObject, Window& window) override;
	// make them one - dynamic type ? 
	virtual void handleCollision(King& gameObject, Window& window) override;
	virtual void handleCollision(Warrior& gameObject, Window& window) override;
	virtual void handleCollision(Mage& gameObject, Window& window) override;
	virtual void handleCollision(Thief& gameObject, Window& window) override;

	virtual void handleCollision(Fire& gameObject, Window& window) override;
	virtual void handleCollision(Gate& gameObject, Window& window) override;
	virtual void handleCollision(Key& gameObject, Window& window) override;
	virtual void handleCollision(Orc& gameObject, Window& window) override;
	virtual void handleCollision(Teleport& gameObject, Window& window) override;
	virtual void handleCollision(Throne& gameObject, Window& window) override;
	virtual void handleCollision(Wall& gameObject, Window& window) override;

	//virtual void handleCollision(Dwarf& gameObject) override;
	//virtual void handleCollision(Bonus& gameObject) override;
private:

};