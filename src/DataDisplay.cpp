#include "DataDisplay.h"


DataDisplay::DataDisplay(int time)
	: m_bgRectangle(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H)),
	m_timeCounter(time),
	m_hasKey(false),
	m_volumeBtn(*(Resources::instance().getVolumeIcon(true))),
	m_homeBtn(*(Resources::instance().getHomeBtnTexture())),
	m_retryLevelBtn(*(Resources::instance().getRetryBtnTexture()))
{
	setText();
	setHomeBtn();
	setRetryLevelBtn();
	setVolumeBtn();
	setLevelNum(1);
	setBgRectangle();
}

//-----------------------------------------------------------------

void DataDisplay::draw(sf::RenderWindow& window, int activePlayer)
{	
	window.draw(m_bgRectangle);

	drawTime(window);
	drawLevelNum(window);
	drawActivePlayer(window, activePlayer);
	drawHasKey(window);

	window.draw(m_volumeBtn);
	window.draw(m_retryLevelBtn);
	window.draw(m_homeBtn);
}

//-----------------------------------------------------------------

void DataDisplay::drawTime(sf::RenderWindow& window )
{
	int sec = 0, min = 0;
	calcTime(sec, min);

	std::string time = (min < 10 ? "0" : "") + std::to_string(min) + ":" + (sec < 10 ? "0" : "") + std::to_string(sec);
	m_timerTxt.setString("Time: " + time);

	window.draw(m_timerTxt);
}

//-----------------------------------------------------------------

void DataDisplay::drawHasKey(sf::RenderWindow& window)
{
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
	m_activePlayerTxt.setString("Player: " + PLAYERS_NAMES[activePlayer]);
	window.draw(m_activePlayerTxt);
}

//-----------------------------------------------------------------

void DataDisplay::calcTime(int& sec, int& min) const
{
	sec = int(m_timeCounter.getTime());

	if (sec >= 60)
	{
		min = sec / 60;
		sec = sec % 60;
	}
}

//-----------------------------------------------------------------

void DataDisplay::setHasKey(bool hasKey)
{
	m_hasKey = hasKey;
}

//-----------------------------------------------------------------

void DataDisplay::setLevelNum(int levelNum)
{
	m_levelNumTxt.setString("Level " + std::to_string(levelNum));
}

//-----------------------------------------------------------------

int DataDisplay::handleClick(const sf::Event &event) const
{
	if (m_volumeBtn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		return VOLUME;
	else if (m_homeBtn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		return HOME;
	else if (m_retryLevelBtn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		return RETRY;
	return MINUS_ONE;
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

void DataDisplay::addTime(const int time)
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

void DataDisplay::setText()
{
	setLevelNumText();
	setActivePlayerText();
	setHasKeyText();
	setTimerText();
}

//-----------------------------------------------------------------

void DataDisplay::setTimerText()
{
	auto posX = m_hasKeyTxt.getPosition().x + m_hasKeyTxt.getGlobalBounds().width + 65;

	m_timerTxt.setFont(*(Resources::instance().getFont()));
	m_timerTxt.setString("Time: 00:00");
	m_timerTxt.setPosition(sf::Vector2f(posX ,DATA_DISPLAY_POS_Y)); // top right
	m_timerTxt.setFillColor(WHITE_COLOR);
	m_timerTxt.setCharacterSize(DATA_DISPLAY_FONT_SIZE);
}

//-----------------------------------------------------------------

void DataDisplay::setLevelNumText()
{
	m_levelNumTxt.setFont(*(Resources::instance().getFont()));
	m_levelNumTxt.setPosition(sf::Vector2f(MARGIN, DATA_DISPLAY_POS_Y));
	m_levelNumTxt.setFillColor(WHITE_COLOR);
	m_levelNumTxt.setCharacterSize(DATA_DISPLAY_FONT_SIZE);
	setLevelNum(0);
}

//-----------------------------------------------------------------

void DataDisplay::setActivePlayerText()
{
	auto posX = m_levelNumTxt.getPosition().x + m_levelNumTxt.getGlobalBounds().width + 65;

	m_activePlayerTxt.setFont(*(Resources::instance().getFont()));
	m_activePlayerTxt.setPosition(sf::Vector2f(posX, DATA_DISPLAY_POS_Y));
	m_activePlayerTxt.setFillColor(WHITE_COLOR);
	m_activePlayerTxt.setCharacterSize(DATA_DISPLAY_FONT_SIZE);
}

//-----------------------------------------------------------------

void DataDisplay::setHasKeyText()
{
	auto posX = m_activePlayerTxt.getPosition().x + 320;

	m_hasKeyTxt.setFont(*(Resources::instance().getFont()));
	m_hasKeyTxt.setPosition(sf::Vector2f(posX, DATA_DISPLAY_POS_Y));
	m_hasKeyTxt.setFillColor(WHITE_COLOR);
	m_hasKeyTxt.setCharacterSize(DATA_DISPLAY_FONT_SIZE);
	m_hasKeyTxt.setString("Key Not Found");
}

//-----------------------------------------------------------------

void DataDisplay::setBgRectangle()
{
	m_bgRectangle.setFillColor(DATA_DISPLAY_BACKGROUMD_COLOR);
	m_bgRectangle.setPosition(sf::Vector2f(0, BOARD_H));
	m_bgRectangle.setSize(sf::Vector2f(DATA_DISPLAY_W, DATA_DISPLAY_H));
}

//-----------------------------------------------------------------

void DataDisplay::setVolumeBtn()
{
	float margin = 0, posX = 0, scale_val = 0.07f;
	m_volumeBtn.scale(scale_val, scale_val);

	margin = 30.f;
	posX = m_retryLevelBtn.getPosition().x - m_volumeBtn.getGlobalBounds().width - margin;

	m_volumeBtn.setPosition(posX, DATA_DISPLAY_POS_Y);
}

//-----------------------------------------------------------------

void DataDisplay::setHomeBtn()
{
	float margin = 0, posX = 0, scale_val = 0.07f;

	m_homeBtn.scale(scale_val, scale_val);

	margin = 30.f;
	posX = WINDOW_W - m_homeBtn.getGlobalBounds().width - margin;

	m_homeBtn.setPosition(posX, DATA_DISPLAY_POS_Y);
}

void DataDisplay::setRetryLevelBtn()
{
	float margin = 0, posX = 0, scale_val = 0.07f;
	m_retryLevelBtn.scale(scale_val, scale_val);

	margin = 50.f;
	posX = WINDOW_W - (m_retryLevelBtn.getGlobalBounds().width + m_homeBtn.getGlobalBounds().width) - margin;

	m_retryLevelBtn.setPosition(posX, DATA_DISPLAY_POS_Y);
}



