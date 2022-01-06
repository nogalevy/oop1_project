#pragma once

#include <SFML/Graphics.hpp>
#include "utilities.h"
#include "view_constants.h"
#include "Resources.h"

class Window;

class King;
class Mage;
class Thief;
class Warrior;

class Wall;
class Gate;
class Fire;
class Teleport;
class Throne;
class Orc;
class Key;

//class Dwarf;
//class Bonus;


class GameObject {
public:
	/*
	- draw
	- getSymbol
	- getTexture
	- getPosition
	*/

	GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight);
	virtual ~GameObject() = default;

	virtual void draw(sf::RenderWindow& window);
	bool checkColisionWith(const GameObject &obj) const;// = 0;

	virtual void handleCollision(GameObject& gameObject, Window& window) = 0;

	virtual void handleCollision(King& gameObject, Window& window) = 0;
	virtual void handleCollision(Warrior& gameObject, Window& window) = 0;
	virtual void handleCollision(Mage& gameObject, Window& window) = 0;
	virtual void handleCollision(Thief& gameObject, Window& window) = 0;

	virtual void handleCollision(Fire& gameObject, Window& window) = 0;
	virtual void handleCollision(Gate& gameObject, Window& window) = 0;
	virtual void handleCollision(Key& gameObject, Window& window) = 0;
	virtual void handleCollision(Orc& gameObject, Window& window) = 0;
	virtual void handleCollision(Teleport& gameObject, Window& window) = 0;
	virtual void handleCollision(Throne& gameObject, Window& window) = 0;
	virtual void handleCollision(Wall& gameObject, Window& window) = 0;

	//virtual void handleCollision(Dwarf& gameObject) = 0;
	//virtual void handleCollision(Bonus& gameObject) = 0;


protected:
	/*
	Members:
	- position
	- symbol
	- texture
	*/

	sf::Sprite m_icon;
	//sf::RectangleShape m_icon;
//	sf::Texture m_texture;
	//sf::Sprite m_icon;

};