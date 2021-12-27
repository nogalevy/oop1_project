#pragma once
#include <SFML/Graphics.hpp>
#include "utilities.h"
#include "view_constants.h"


class GameObject {
public:
	/*
	- draw
	- getSymbol
	- getTexture
	- getPosition
	*/

	GameObject(Icons symbol, const sf::Vector2f& location, int mapWidth, int mapHeight);
	~GameObject();

	virtual void draw(sf::RenderWindow& window);


protected:
	/*
	Members:
	- position
	- symbol
	- texture
	*/
	sf::RectangleShape m_icon;
	sf::Texture m_texture;
	//sf::Sprite m_icon;

};