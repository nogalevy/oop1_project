#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Timer.h"
#include "view_constants.h"
#include "utilities.h"
#include "Resources.h"

const int FONT_SIZE = 30; //need to put this somewhere else??

class DataDisplay 
{
public:
	DataDisplay(); //delete? T: why?
	DataDisplay(int time);
	~DataDisplay() = default;

	void draw(sf::RenderWindow& window, int activePlayer);
	int handleClick(sf::Event event)const;

	void updateVolumeIcon(bool soundOn);

	//Time Functions
	void resetClock();
	bool isTimeEnd()const;
	void addTime(const int time, sf::RenderWindow& window);
	
	//Set Functions
	void setLevelNum(int levelNum);
	void setHasKey(bool hasKey);
	void setCountdown(int time);

private:
	//Set Functions
	void setBgRectangle();
	void setVolumeBtn();
	void setHomeBtn();

	//Draw Functions
	void drawTime(sf::RenderWindow& window);
	void drawHasKey(sf::RenderWindow& window);
	void drawLevelNum(sf::RenderWindow& window);
	void drawActivePlayer(sf::RenderWindow& window, int activePlayer);


	//======Members==========

	sf::RectangleShape m_bgRectangle;

	sf::Text m_timerTxt;
	sf::Text m_levelNumTxt;
	sf::Text m_activePlayerTxt;
	sf::Text m_hasKeyTxt;
	sf::Sprite m_volumeBtn;
	sf::Sprite m_homeBtn;

	timer_type m_timerType;
	Timer m_timeCounter;

	bool m_hasKey;

};
