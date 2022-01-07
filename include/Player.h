#pragma once
#include "MovingObject.h"


class Player : public MovingObject
{
public:
	Player(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	virtual ~Player();


	void move(sf::Vector2f direction, sf::Time deltaTime);// = 0;
private:
};