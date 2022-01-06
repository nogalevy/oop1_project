#pragma once
#include "Player.h"


class Thief: public Player 
{
public:
	Thief(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~Thief();

	//virtual void move(sf::Vector2f direction, sf::Time deltaTime) override;

	//// Colisions:
	virtual void handleCollision(GameObject& gameObject, Window& window) override;

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

	bool getHasKey()const;
private:
	void setHasKey(bool hasKey);

	bool m_hasKey;
};
	/*
	bool m_hasKey;
	*/
	//bool m_hasKey;