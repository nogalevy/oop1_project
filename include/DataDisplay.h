#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Timer.h"
#include "view_constants.h"
#include "utilities.h"
#include "Resources.h"


class DataDisplay 
{
public:
	DataDisplay(int time);
	~DataDisplay() = default;

	//Draw Functions
	void draw(sf::RenderWindow& window, int activePlayer);

	//Event Functions
	int handleClick(const sf::Event &event)const;

	//Time Functions
	void resetClock();
	bool isTimeEnd()const;
	void addTime(const int time);
	
	//Set Functions
	void setLevelNum(int levelNum);
	void setHasKey(bool hasKey);
	void setCountdown(int time);
	void updateVolumeIcon(bool soundOn);

private:
	//Set Functions
	void setText();
	void setTimerText();
	void setLevelNumText();
	void setActivePlayerText();
	void setHasKeyText();
	void setBgRectangle();
	void setVolumeBtn();
	void setHomeBtn();

	//Draw Functions
	void drawTime(sf::RenderWindow& window);
	void drawHasKey(sf::RenderWindow& window);
	void drawLevelNum(sf::RenderWindow& window);
	void drawActivePlayer(sf::RenderWindow& window, int activePlayer);

	//Time Functions
	void calcTime(int &sec, int &min)const;

	//======Members==========

	sf::RectangleShape m_bgRectangle;

	//Text
	sf::Text m_timerTxt;
	sf::Text m_levelNumTxt;
	sf::Text m_activePlayerTxt;
	sf::Text m_hasKeyTxt;

	//Buttons
	sf::Sprite m_volumeBtn;
	sf::Sprite m_homeBtn;

	//Time Members
	Timer m_timeCounter;

	bool m_hasKey;
};
