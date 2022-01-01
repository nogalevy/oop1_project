#pragma once
#include <SFML/Graphics.hpp>
#include "utilities.h"
#include "view_constants.h"
#include "Resources.h"


class GameObject {
public:
	/*
	- draw
	- getSymbol
	- getTexture
	- getPosition
	*/

	GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight);
	virtual ~GameObject();

	virtual void draw(sf::RenderWindow& window);
	bool checkColisionWith(const GameObject &obj) const;// = 0;


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