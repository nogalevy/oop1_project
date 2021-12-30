#pragma once
#include "DynamicObject.h"

class Thief: public DynamicObject 
{
public:
	Theif(Icons symbol, const sf::Vector2f& position, int mapW, int mapH);
	~Theif();
private:
	/*
	bool m_hasKey;
	*/
	bool m_hasKey;
};