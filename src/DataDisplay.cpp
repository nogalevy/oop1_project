#include "DataDisplay.h"

DataDisplay::DataDisplay()
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter(),
	m_hasKey(false)
{
	m_timerTxt.setFont(*(Resources::instance().getDataFont()));
	m_activePlayerTxt.setFont(*(Resources::instance().getDataFont()));
	m_hasKeyTxt.setFont(*(Resources::instance().getDataFont()));
	m_levelNumTxt.setFont(*(Resources::instance().getDataFont()));
	setLevelNum(1);
	setBgRectangle();
}

DataDisplay::DataDisplay(float time)
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter(time)
{
	m_timerTxt.setFont(*(Resources::instance().getDataFont()));
	setBgRectangle();
}

void DataDisplay::draw(sf::RenderWindow& window, int activePlayer)
{	
	drawTime(window);
	drawLevelNum(window);
	drawActivePlayer(window, activePlayer);
	drawHasKey(window);
}

void DataDisplay::drawTime(sf::RenderWindow& window )
{

	int sec = int(m_timeCounter.getTime());
	int minutes = 0;

	if (sec >= 60)
	{
		minutes = sec / 60;
		sec = sec % 60;
	}

	m_timerTxt.setString("Time: " + std::to_string(minutes) + ":" + (sec < 10 ? "0" : "") + std::to_string(sec));
	//m_timerTxt.setPosition(sf::Vector2f(0, BOARD_H + 10));
	m_timerTxt.setPosition(sf::Vector2f(10, 10)); //option #1 top left
	//m_timerTxt.setPosition(sf::Vector2f(WINDOW_W - m_timerTxt.getGlobalBounds().width - 10, BOARD_H + 10)); //option #2 bottom right
	m_timerTxt.setPosition(sf::Vector2f(WINDOW_W - m_timerTxt.getGlobalBounds().width - 10,10)); //option #3 top right
	m_timerTxt.setColor(sf::Color::White);
	m_timerTxt.setCharacterSize(20);



	//example how to + or - time
	if (int(m_timeCounter.getTime()) == 0)
	{
		m_timeCounter.addTime(10);
	}

	window.draw(m_timerTxt);
}

void DataDisplay::drawHasKey(sf::RenderWindow& window)
{
	//int posX = m_activePlayerTxt.getPosition().x + m_activePlayerTxt.getGlobalBounds().width + 65;
	int posX = m_activePlayerTxt.getPosition().x + 370;
	m_hasKeyTxt.setPosition(sf::Vector2f(posX, BOARD_H + 10));
	m_hasKeyTxt.setColor(sf::Color::White);
	m_hasKeyTxt.setCharacterSize(20);

	m_hasKeyTxt.setString(m_hasKey ? "Key Found" : "Key Not Found");
	window.draw(m_hasKeyTxt);
}

void DataDisplay::drawLevelNum(sf::RenderWindow& window)
{
	window.draw(m_levelNumTxt);
}

void DataDisplay::drawActivePlayer(sf::RenderWindow& window, int activePlayer)
{
	int posX = m_levelNumTxt.getPosition().x + m_levelNumTxt.getGlobalBounds().width + 65;
	m_activePlayerTxt.setPosition(sf::Vector2f(posX, BOARD_H + 10));
	m_activePlayerTxt.setColor(sf::Color::White);
	m_activePlayerTxt.setCharacterSize(20);

	m_activePlayerTxt.setString("Player: " + PLAYERS_NAMES[activePlayer]);
	window.draw(m_activePlayerTxt);
}

void DataDisplay::setHasKey(bool hasKey)
{
	m_hasKey = hasKey;
}

void DataDisplay::setLevelNum(int levelNum)
{
	m_levelNumTxt.setPosition(sf::Vector2f(10, BOARD_H + 10));
	m_levelNumTxt.setColor(sf::Color::White);
	m_levelNumTxt.setCharacterSize(20);

	m_levelNumTxt.setString("Level " + std::to_string(levelNum));
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


