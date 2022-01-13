#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Timer.h"
#include "view_constants.h"
#include "utilities.h"
#include "Resources.h"

const int FONT_SIZE = 30;

class DataDisplay {
public:
	// constructor
	DataDisplay(); //delete?
	DataDisplay(int time);

	void draw(sf::RenderWindow& window, int activePlayer);
	void resetClock();
	void drawTime(sf::RenderWindow& window);
	void drawHasKey(sf::RenderWindow& window);
	void drawLevelNum(sf::RenderWindow& window);
	void drawActivePlayer(sf::RenderWindow& window, int activePlayer);
	void setHasKey(bool hasKey);
	void setLevelNum(int levelNum);
	int handleClick(sf::Event event)const;
	void updateVolumeIcon(bool soundOn);

	void setCountdown(int time);

	void addTime(const int time, sf::RenderWindow& window);
	bool isTimeEnd()const;
private:
	void setBgRectangle();
	void setVolumeBtn();
	void setHomeBtn();
	sf::RectangleShape m_bgRectangle;

	sf::Text m_timerTxt;
	sf::Text m_levelNumTxt;
	sf::Text m_activePlayerTxt;
	sf::Text m_hasKeyTxt;
	sf::Sprite m_volumeBtn;
	sf::Sprite m_homeBtn;

	timer_type m_timerType; // 
	Timer m_timeCounter;

	bool m_hasKey;
	// key ?
	// current player ? or get this data from board? 
};
