#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "view_constants.h"
#include "utilities.h"


class Timer
{
public:
	Timer();
	Timer(int time);

	void setTime(int time);
	void startClock();
	sf::Time getElapsed();
	void addTime(float time_to_add);
	//void draw(sf::RenderWindow& window);
	float getTime();

private:
	sf::Clock m_clock;
	sf::Time m_time;
	timer_type m_timerType; // true = timer | false = countdown
};

