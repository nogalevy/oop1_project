#include "DataDisplay.h"

DataDisplay::DataDisplay()
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter()
{
	m_timerTxt.setFont(*(Resources::instance().getDataFont()));
	setBgRectangle();
}

DataDisplay::DataDisplay(float time)
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter(time)
{
	m_timerTxt.setFont(*(Resources::instance().getDataFont()));
	setBgRectangle();
}



void DataDisplay::draw(sf::RenderWindow& window)
{	
	drawTime(window);
	drawHasKey(window);
	drawLevelNum(window);
	drawActivePlayer(window);
}

void DataDisplay::drawTime(sf::RenderWindow& window)
{
	m_timerTxt.setPosition(sf::Vector2f(0, BOARD_H + 10));
	m_timerTxt.setColor(sf::Color::White);
	m_timerTxt.setCharacterSize(20);

	int sec = int(m_timeCounter.getTime());
	int minutes = 0;

	if (sec >= 60)
	{
		minutes = sec / 60;
		sec = sec % 60;
	}

	m_timerTxt.setString(std::to_string(minutes) + ":" + (sec < 10 ? "0" : "") + std::to_string(sec));

	//example how to + or - time
	if (int(m_timeCounter.getTime()) == 0)
	{
		m_timeCounter.addTime(10);
	}

	window.draw(m_timerTxt);
}

void DataDisplay::drawHasKey(sf::RenderWindow& window)
{
	//m_hasKeyTxt.setString("Key: ");
}

void DataDisplay::drawLevelNum(sf::RenderWindow& window)
{
	//m_levelNumTxt.setString("Level: ");
}

void DataDisplay::drawActivePlayer(sf::RenderWindow& window)
{
	//m_levelNumTxt.setString("Player: ");
}

void DataDisplay::resetClock()
{
	m_timeCounter.startClock();
}

void DataDisplay::setBgRectangle()
{
	m_bgRectangle.setFillColor(sf::Color::Color(41, 54, 37));
	m_bgRectangle.setPosition(sf::Vector2f(0, BOARD_H));
}

