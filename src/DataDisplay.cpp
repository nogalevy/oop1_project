#include "DataDisplay.h"

DataDisplay::DataDisplay()
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter()
{
	if (!m_font.loadFromFile("font2.ttf"));
	{
		
	}
	m_timerTxt.setFont(m_font);
	setBgRectangle();
}

DataDisplay::DataDisplay(float time)
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter(time)
{
	if (!m_font.loadFromFile("font2.ttf"));
	{

	}
	m_timerTxt.setFont(m_font);
	setBgRectangle();
}



void DataDisplay::draw(sf::RenderWindow& window)
{
	//sf::Clock m_clock;
	
	//sf::Time elapsed = m_clock.getElapsedTime();
	//window.draw(m_bgRectangle);

	m_timerTxt.setPosition(sf::Vector2f(0, BOARD_H + 10));
	m_timerTxt.setColor(sf::Color::White);
	m_timerTxt.setCharacterSize(20);
	////auto el = (elapsed.asSeconds() )* 10;
	
	//m_timerTxt.setString(std::to_string(elapsed.asSeconds()));
	/*int sec = int(m_timeCounter.getTime());
	int minutes = 0;
	
	if (sec >= 60)
	{
		minutes = sec / 60;
		sec = sec % 60;
	}

	m_timerTxt.setString(std::to_string(minutes)+ ":" + (sec < 10 ? "0" : "") + std::to_string(sec));

	if (int(m_timeCounter.getTime()) == 0)
	{
		std::cout << " here\n";
		m_timeCounter.addTime(10);
	}*/
	drawTime(window);
	//sf::Time t3 = sf::seconds(60);
	//m_timerTxt.setString(std::to_string(t3.asSeconds() - elapsed.asSeconds()));


	window.draw(m_timerTxt);
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

