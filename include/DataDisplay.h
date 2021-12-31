#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Timer.h"
#include "view_constants.h"
#include "utilities.h"

class DataDisplay {
public:
	// constructor
	DataDisplay();
	DataDisplay(float time);

	// draw (key , timer, current player, level num)
	void draw(sf::RenderWindow & window);
	void resetClock();
	void drawTime(sf::RenderWindow& window);
	// hasKey
	// updaeCurrPlayer ?
private:
	void setBgRectangle();

	sf::Font m_font;
	sf::RectangleShape m_bgRectangle;
	sf::Text m_timerTxt;
	
	timer_type m_timerType; // 
	Timer m_timeCounter;
	// key ?
	// current player ? or get this data from board? 
};
