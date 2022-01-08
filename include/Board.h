#pragma once

#include <SFML/Graphics.hpp>
#include "view_constants.h"
#include "utilities.h"
#include <fstream>
#include <memory>
#include "MovingObject.h"
#include "StaticObject.h"
#include "Player.h"
#include <vector>

#include "Thief.h"
#include "Mage.h"
#include "Warrior.h"
#include "King.h"
#include "Wall.h"
#include "Gate.h"
#include "Fire.h"
#include "Teleport.h"
#include "Throne.h"
#include "Orc.h"
#include "Key.h"
#include "AddTimeBonus.h"
#include "Dwarf.h"


//class MovingObject;
//class StaticObject;
//class Wall;
//class King;
//class Thief;
//class Warrior;
//class Mage;



class Board 
{
public:
	Board();
	~Board();
	void draw(sf::RenderWindow& window);
	void move(sf::Vector2f direction, sf::Time timer, int activePlayer);
	void readLevel();
	Icons getSymbol(int, int);
	int getHeight();
	int getWidth();

	void moveDwarfs();
	bool getHasKey() const;
	void loadNextLevel();
	bool setLevelNum();

private:
	void openLevelFile();
	bool checkHasKey() const;
	void readLevelSize();
	void createObjects();
	bool isStaticObj(Icons symbol);
	void setBgRectangle();
	void createMat();
	void handleCollisions(int activePlayer);
	void updateBoard();
	void removeStaticObjects();
	void changeStatic();

	int m_width;
	int m_height;
	std::ifstream m_levelFile;
	std::vector<std::string> m_boardMat;

	std::vector<std::unique_ptr<Player>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	std::vector<std::unique_ptr<Dwarf>> m_dwarfs;

	sf::RectangleShape m_bgRectangle;


	//Trial
	std::vector<std::vector<sf::RectangleShape>>m_mat;
	std::vector<std::vector<sf::RectangleShape>> initMat(int size, int square_size);

	void initSquare(int row, int col, int square_size);
	//sf::Vector2f getPosition(int row, int col);

	int m_levelNum;

	//data from players:
	bool m_hasKey;
	bool m_endLevel;
};