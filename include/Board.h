#pragma once

#include <SFML/Graphics.hpp>
#include "view_constants.h"

class Board 
{
public:
	Board(int width, int height);
	void draw(sf::RenderWindow& window);
	void move(int direction, int activePlayer);
	void moveRect(int dir);
private:
	sf::RectangleShape rect;
};