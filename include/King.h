#pragma once

#include "DynamicObject.h"

class King : public DynamicObject
{
public:
	King(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~King();

	virtual void move(/*sf::Time&*/) override;

private:

};
