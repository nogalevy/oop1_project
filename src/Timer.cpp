#include "Timer.h"

//create timer
//Timer::Timer() 
//	: m_time(), m_clock(), m_timerType(TIMER) {}

//create countdown
Timer::Timer(int time)
	: m_time(sf::seconds(time)), m_clock(), m_timerType(TIMER) 
{
	setTime(time);
	m_timerType = time == -1 ? TIMER : COUNTDOWN;
}

void Timer::setTime(int time)
{
	m_time = sf::seconds(time);
}

//void Timer::setCountdown(int time)
//{
//	m_timerType;
//	m_time.
//}

void Timer::startClock()
{
	m_clock.restart();
}

sf::Time Timer::getElapsed()
{
	return m_clock.getElapsedTime();
}

void Timer::addTime(float time_to_add)
{
	sf::Time t = sf::seconds(time_to_add);
	auto sumSec = m_time.asSeconds() + t.asSeconds();
	m_time = sf::seconds(sumSec < 0 ? 0 : sumSec);
}

float Timer::getTime()
{
	if (m_timerType == TIMER) m_clock.getElapsedTime().asSeconds();
	else if (m_time.asSeconds() - m_clock.getElapsedTime().asSeconds() <= 0) return 0;
	else return m_time.asSeconds() - m_clock.getElapsedTime().asSeconds();
}
