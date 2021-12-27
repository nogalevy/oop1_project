#pragma once

#include <SFML/Graphics.hpp>
#include "view_constants.h"

#include <fstream>

class Board 
{
public:
	Board();
	void draw(sf::RenderWindow& window);
	void move(sf::Vector2f direction, sf::Time timer, int activePlayer);
	void moveRect(sf::Vector2f direction, sf::Time deltaTime);
	void readLevel();
private:
	void readLevelSize();
	sf::RectangleShape rect;
	int m_width;
	int m_height;
	std::ifstream m_levelFile;
	std::vector<std::string> m_boardMat;

};