#include "DataDisplay.h"

DataDisplay::DataDisplay()
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter(-1),
	m_hasKey(false),
	m_volumeBtn(*(Resources::instance().getVolumeIcon(true))),
	m_homeBtn(*(Resources::instance().getHomeBtnTexture()))
{
	m_timerTxt.setFont(*(Resources::instance().getFont()));
	m_activePlayerTxt.setFont(*(Resources::instance().getFont()));
	m_hasKeyTxt.setFont(*(Resources::instance().getFont()));
	m_levelNumTxt.setFont(*(Resources::instance().getFont()));

	setHomeBtn();
	setVolumeBtn();
	setLevelNum(1);
	setBgRectangle();
}

//-----------------------------------------------------------------

DataDisplay::DataDisplay(int time)
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter(time),
	m_hasKey(false),
	m_volumeBtn(*(Resources::instance().getVolumeIcon(true))),
	m_homeBtn(*(Resources::instance().getHomeBtnTexture()))
{
	m_timerTxt.setFont(*(Resources::instance().getFont()));
	m_activePlayerTxt.setFont(*(Resources::instance().getFont()));
	m_hasKeyTxt.setFont(*(Resources::instance().getFont()));
	m_levelNumTxt.setFont(*(Resources::instance().getFont()));

	setHomeBtn();
	setVolumeBtn();
	setLevelNum(1);
	setBgRectangle();
}

//-----------------------------------------------------------------

void DataDisplay::draw(sf::RenderWindow& window, int activePlayer)
{	
	drawTime(window);
	drawLevelNum(window);
	drawActivePlayer(window, activePlayer);
	drawHasKey(window);

	window.draw(m_volumeBtn);
	window.draw(m_homeBtn);
}

//-----------------------------------------------------------------

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
	m_timerTxt.setCharacterSize(FONT_SIZE);

	window.draw(m_timerTxt);
}

//-----------------------------------------------------------------

void DataDisplay::drawHasKey(sf::RenderWindow& window)
{
	//int posX = m_activePlayerTxt.getPosition().x + m_activePlayerTxt.getGlobalBounds().width + 65;
	int posX = m_activePlayerTxt.getPosition().x + 370;
	m_hasKeyTxt.setPosition(sf::Vector2f(posX, BOARD_H + 10));
	m_hasKeyTxt.setColor(sf::Color::White);
	m_hasKeyTxt.setCharacterSize(FONT_SIZE);

	m_hasKeyTxt.setString(m_hasKey ? "Key Found" : "Key Not Found");
	window.draw(m_hasKeyTxt);
}

//-----------------------------------------------------------------

void DataDisplay::drawLevelNum(sf::RenderWindow& window)
{
	window.draw(m_levelNumTxt);
}

//-----------------------------------------------------------------

void DataDisplay::drawActivePlayer(sf::RenderWindow& window, int activePlayer)
{
	int posX = m_levelNumTxt.getPosition().x + m_levelNumTxt.getGlobalBounds().width + 65;
	m_activePlayerTxt.setPosition(sf::Vector2f(posX, BOARD_H + 10));
	m_activePlayerTxt.setColor(sf::Color::White);
	m_activePlayerTxt.setCharacterSize(FONT_SIZE);

	m_activePlayerTxt.setString("Player: " + PLAYERS_NAMES[activePlayer]);
	window.draw(m_activePlayerTxt);
}

//-----------------------------------------------------------------

void DataDisplay::setHasKey(bool hasKey)
{
	m_hasKey = hasKey;
}

//-----------------------------------------------------------------

void DataDisplay::setLevelNum(int levelNum)
{
	m_levelNumTxt.setPosition(sf::Vector2f(10, BOARD_H + 10));
	m_levelNumTxt.setColor(sf::Color::White);
	m_levelNumTxt.setCharacterSize(FONT_SIZE);

	m_levelNumTxt.setString("Level " + std::to_string(levelNum));
}

//-----------------------------------------------------------------

int DataDisplay::handleClick(sf::Event event) const
{

	if (m_volumeBtn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		return VOLUME;
	else if (m_homeBtn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		return HOME;
	return -1;
}

//-----------------------------------------------------------------

void DataDisplay::updateVolumeIcon(bool soundOn)
{
	m_volumeBtn.setTexture(*(Resources::instance().getVolumeIcon(soundOn)));
}

//-----------------------------------------------------------------

void DataDisplay::setCountdown(int time)
{
	m_timeCounter = Timer(time);
}

//-----------------------------------------------------------------

void DataDisplay::addTime(const int time, sf::RenderWindow& window)
{
	m_timeCounter.addTime((float)time);
}

//-----------------------------------------------------------------

bool DataDisplay::isTimeEnd()const
{
	return (m_timeCounter.getType() == COUNTDOWN && int(m_timeCounter.getTime()) == 0);
}

//-----------------------------------------------------------------

void DataDisplay::resetClock()
{
	m_timeCounter.startClock();
}

//-----------------------------------------------------------------

void DataDisplay::setBgRectangle()
{
	m_bgRectangle.setFillColor(sf::Color::Color(26, 26, 26));
	m_bgRectangle.setPosition(sf::Vector2f(0, BOARD_H));
	m_bgRectangle.setSize(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H));
}

//-----------------------------------------------------------------

void DataDisplay::setVolumeBtn()
{
	float margin = 0, posX = 0;
	m_volumeBtn.scale(0.07, 0.07);

	margin = 40.f;
	//posX = WINDOW_W - m_volumeBtn.getGlobalBounds().width - margin;

	posX = WINDOW_W - (m_volumeBtn.getGlobalBounds().width + m_homeBtn.getGlobalBounds().width) - margin;

	m_volumeBtn.setPosition(posX, BOARD_H + 10);
}

//-----------------------------------------------------------------

void DataDisplay::setHomeBtn()
{
	float margin = 0, posX = 0;
	m_homeBtn.scale(0.07, 0.07);

	margin = 20.f;
	//posX = WINDOW_W - (m_homeBtn.getGlobalBounds().width + m_volumeBtn.getGlobalBounds().width)- margin;
	posX = WINDOW_W - m_homeBtn.getGlobalBounds().width - margin;

	m_homeBtn.setPosition(posX, BOARD_H + 10);
}



