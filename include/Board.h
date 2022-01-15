#pragma once

#include <fstream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "view_constants.h"
#include "utilities.h"

#include "movingInclude/MovingObject.h"
#include "movingInclude/Player.h"
#include "movingInclude/Thief.h"
#include "movingInclude/Mage.h"
#include "movingInclude/Warrior.h"
#include "movingInclude/King.h"
#include "movingInclude/Dwarf.h"

#include "staticInclude/StaticObject.h"
#include "staticInclude/Wall.h"
#include "staticInclude/Gate.h"
#include "staticInclude/Fire.h"
#include "staticInclude/Teleport.h"
#include "staticInclude/Throne.h"
#include "staticInclude/Orc.h"
#include "staticInclude/Key.h"
#include "staticInclude/AddTimeBonus.h"
#include "staticInclude/SubTimeBonus.h"
#include "staticInclude/RmvDwarfsBonus.h"
#include "staticInclude/MoreDwarfsBonus.h"
#include "staticInclude/SlowDwarfsBonus.h"
#include "staticInclude/FastDwarfsBonus.h"


class Board
{
public:
	Board();
	~Board();

	//Access Functions
	int getHeight()const;
	int getWidth()const;
	bool isCountdown()const;
	int getCountdown()const;
	bool getHasKey() const;
	BonusType getBonus()const;
	bool getEndlevel() const;
	int getLevelNum()const;

	//Draw Function
	void draw(sf::RenderWindow& window,const int activePlayer);

	//Move Functions
	void move(sf::Vector2f direction, sf::Time timer,const int activePlayer);
	void moveDwarfs(sf::Time);

	//Level Functions
	bool setLevelNum();
	void loadLevel();
	void resetLevelNum();
	void removeDwarfs();
	void moreDwarfs();
	void fastDwarfs();
	void slowDwarfs();

	void createLevel();
	void setBonus(BonusType type);
private:
	//Access Functions
	Icons getSymbol(const int,const int)const;
	float getObjSizeOnBoard()const;

	//Level Functions
	void readLevel();
	bool checkEndLevel() const;
	void openLevelFile();
	void readCountdown();
	void readLevelSize();
	void initPartners();

	//Objects Functions
	void createObjects(float obj_size);
	bool isStaticObj(const Icons symbol)const;
	void removeStaticObjects();
	void changeStatic();
	void createMoving(Icons symbol, sf::Vector2f position, float obj_size);
	void createStatic(Icons symbol, sf::Vector2f position, float obj_size);
	std::unique_ptr<Bonus> selectRandomBonus(sf::Vector2f position, float obj_size);
	void initTeleportPartners(float obj_size);
	bool canAddDwarf(const int row, int& col)const;
	void addDwarfToRow(const int row, const int col, float obj_size);

	bool checkHasKey() const;
	void setBgRectangle();
	void handleCollisions(const int activePlayer);
	void handleDwarfCollisions();
	void updateBoard();

	sf::Vector2f createPosition(int row, int col, int symbol, float square_size);

	//======Members==========

	int m_width;
	int m_height;

	std::ifstream m_levelFile;
	std::vector<std::string> m_boardMat;

	//Objects
	std::vector<std::unique_ptr<Player>> m_players;
	std::vector<std::unique_ptr<StaticObject>> m_staticObj;
	std::vector<std::unique_ptr<Dwarf>> m_dwarfs;

	std::vector<Partners> m_partners; //Teleport Partners

	sf::RectangleShape m_bgRectangle;

	//Level Data Member
	int m_levelNum;

	//Player Data Members
	bool m_hasKey;
	bool m_endLevel;
	BonusType m_bonusType;

	//Timer Data Members
	bool m_isCountdown;
	int m_countdownTime;
};
