#pragma once

#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	//Wall(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	using StaticObject::StaticObject;
	~Wall();
private:

};