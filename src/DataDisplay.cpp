#include "DataDisplay.h"

DataDisplay::DataDisplay()
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_clock()
{
	if (!m_font.loadFromFile("font2.ttf"));
	{
		
	}
	m_timerTxt.setFont(m_font);
	setBgRectangle();
}

void DataDisplay::draw(sf::RenderWindow& window)
{
	sf::Time elapsed = m_clock.getElapsedTime();
	window.draw(m_bgRectangle);

	m_timerTxt.setPosition(sf::Vector2f(0, BOARD_H + 10));
	m_timerTxt.setColor(sf::Color::White);
	m_timerTxt.setCharacterSize(20);
	//auto el = (elapsed.asSeconds() )* 10;
	m_timerTxt.setString(std::to_string(elapsed.asSeconds()));

	window.draw(m_timerTxt);
}

void DataDisplay::setBgRectangle()
{
	m_bgRectangle.setFillColor(sf::Color::Color(41, 54, 37));
	m_bgRectangle.setPosition(sf::Vector2f(0, BOARD_H));
}
