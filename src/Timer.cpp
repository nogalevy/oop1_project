#include "Timer.h"

//create timer
Timer::Timer() 
	: m_time(), m_clock(), m_timerType(TIMER)
{
}

//create countdown
Timer::Timer(int time)
	: m_time(sf::seconds(time)), m_clock(), m_timerType(COUNTDOWN)
{
}

void Timer::setTime(int time)
{
	m_time = sf::seconds(time);
}

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
	m_time = sf::seconds(m_time.asSeconds() + t.asSeconds());
}

float Timer::getTime()
{
	return m_timerType == TIMER ? m_clock.getElapsedTime().asSeconds() : (m_time.asSeconds() - m_clock.getElapsedTime().asSeconds())  ;
}
