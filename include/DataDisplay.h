#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
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

	sf::Font m_font;
	sf::RectangleShape m_bgRectangle;
	sf::Clock m_clock;
	sf::Text m_timerTxt;
	// key ?
	// current player ? or get this data from board? 
};