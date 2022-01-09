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
#include "SubTimeBonus.h"
#include "RmvDwarfsBonus.h"

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

	void readLevel();

	//Access Functions
	Icons getSymbol(int, int);
	int getHeight();
	int getWidth();

	bool getHasKey() const;
	void loadNextLevel();
	bool setLevelNum();
	//Draw Function
	void draw(sf::RenderWindow& window);

	//Move Functions
	void move(sf::Vector2f direction, sf::Time timer, int activePlayer);
	void moveDwarfs(sf::Time);
	bool getEndlevel() const;
	int getLevelNum()const;

private:
	bool checkEndLevel() const;
	void openLevelFile();
	bool checkHasKey() const;
	void readLevelSize();
	void createObjects();
	bool isStaticObj(Icons symbol);
	void setBgRectangle();
	void createMat();
	void handleCollisions(int activePlayer);
	void handleDwarfCollisions();
	void updateBoard();
	void removeStaticObjects();
	void changeStatic();
	void initPartners();
	sf::Vector2f createPosition(int row, int col);
	void initTeleportPartners();
	std::unique_ptr<Bonus> selectRandomBonus(sf::Vector2f position);



	int m_width;
	int m_height;
	std::ifstream m_levelFile;
	std::vector<std::string> m_boardMat;

	std::vector<std::unique_ptr<Player>> m_movingObj;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	std::vector<std::unique_ptr<Dwarf>> m_dwarfs;

	std::vector<Partners> m_partners;

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
