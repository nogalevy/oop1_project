#pragma once

#include <SFML/Graphics.hpp>
#include "view_constants.h"

class DataDisplay {
public:
	// constructor
	DataDisplay();
	// draw (key , timer, current player, level num)
	void draw(sf::RenderWindow & window);
	// hasKey
	// updaeCurrPlayer ?
private:
	void setBgRectangle();

	sf::RectangleShape m_bgRectangle;
	// timer/countdown
	// key ?
	// current player ? or get this data from board? 
};