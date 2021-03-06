#pragma once

#include <SFML/Graphics.hpp>
#include "utilities.h"
#include "macros.h"
#include "Resources.h"

class King;
class Mage;
class Thief;
class Warrior;
class Dwarf;

class Wall;
class Gate;
class Fire;
class Teleport;
class Throne;
class Orc;
class Key;
class Bonus;

class GameObject {
public:

	GameObject(Icons symbol, const sf::Vector2f& location, float objSize);
	virtual ~GameObject() = default;

	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition()const;

	bool checkColisionWith(const GameObject &obj) const;
	virtual void handleCollision(GameObject& gameObject) = 0;

	//Moving Objects
	virtual void handleCollision(King& gameObject) = 0;
	virtual void handleCollision(Warrior& gameObject) = 0;
	virtual void handleCollision(Mage& gameObject) = 0;
	virtual void handleCollision(Thief& gameObject) = 0;
	virtual void handleCollision(Dwarf& gameObject) = 0;

	//Static Objects
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Orc& gameObject) = 0;
	virtual void handleCollision(Teleport& gameObject) = 0;
	virtual void handleCollision(Throne& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Bonus& gameObject) = 0;

protected:
	sf::Sprite& getIcon();
	void setIcon(sf::Texture &texture);

private:
	sf::Sprite m_icon;
};