#pragma once

#include <SFML/Graphics.hpp>
#include "view_constants.h"
#include "utilities.h"
#include <fstream>
#include <memory>
#include "DynamicObject.h"
#include "StaticObject.h"


//class DynamicObject;
//class StaticObject;
//class Wall;
//class King;

class Board 
{
public:
	Board();
	~Board();
	void draw(sf::RenderWindow& window);
	void move(int direction, int activePlayer);
	void moveRect(int dir);
	void readLevel();
	Icons getSymbol(int, int);

private:
	void readLevelSize();
	void createObjects();
	bool isStaticObj(Icons symbol);

	sf::RectangleShape rect;
	int m_width;
	int m_height;
	std::ifstream m_levelFile;
	std::vector<std::string> m_boardMat;

	std::vector<std::unique_ptr<DynamicObject>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;


};