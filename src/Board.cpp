#include "Board.h"


Board::Board()
	: m_height(0), m_width(0),
	m_bgRectangle(sf::Vector2f(BOARD_W, BOARD_H)),
	m_levelNum(1),
	m_endLevel(false),
	m_hasKey(false)
{
	setBgRectangle();
	openLevelFile();

	//createMat();
}

//-----------------------------------------------------------------

Board::~Board()
{
}

//-----------------------------------------------------------------

void Board::readLevel()
{
	//readCountdown();
	readLevelSize();
	char c;

	m_levelFile.get(c);

	m_boardMat.clear();

	auto line = std::string();
	for (int row = 0; row < m_height; row++)
	{
		getline(m_levelFile, line);
		m_boardMat.push_back(line);
	}
	initPartners();
	readCountdown();
}

//-----------------------------------------------------------------

Icons Board::getSymbol(int row, int col)const
{
	char symbol = m_boardMat[row][col];

	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		if (SYMBOLS[i] == symbol)
			return (Icons)i;
	}

	return SPACE;
}

//-----------------------------------------------------------------

int Board::getHeight()const
{
	return m_height;
}

//-----------------------------------------------------------------

int Board::getWidth()const
{
	return m_width;
}

//-----------------------------------------------------------------

bool Board::isCountdown() const
{
	return m_isCountdown;
}

//-----------------------------------------------------------------

int Board::getCountdown() const
{
	return m_countdownTime;
}

//-----------------------------------------------------------------

bool Board::checkEndLevel() const
{
	for (auto& movable : m_players)
	{
		//auto movingPtr = movable.get();
		if (auto movablePtr = dynamic_cast<King*>(movable.get()))
		{
			return movablePtr->isReachToThrone();
		}
	}
}

//-----------------------------------------------------------------

void Board::openLevelFile()
{
	std::string levelName = "Level" + std::to_string(m_levelNum) + ".txt";

	m_levelFile.open(levelName);
	if (!m_levelFile.is_open())
		std::cout << "Couldn't open file\n";

	createLevel();
}

//-----------------------------------------------------------------

bool Board::checkHasKey() const
{
	for(auto &movable : m_players)
	{
		//auto movingPtr = movable.get();
		if (auto playerPtr = dynamic_cast<Thief*>(movable.get()))
		{
			return playerPtr->getHasKey();	// extract the life member from player before deleting it
		}
	}
	return false;
}

//-----------------------------------------------------------------

void Board::readCountdown()
{
	m_levelFile >> m_countdownTime;

	m_isCountdown = (m_countdownTime == -1) ? false : true;
	std::cout << "Timer Number is: " << m_countdownTime << std::endl;
}

//-----------------------------------------------------------------


void Board::draw(sf::RenderWindow& window, int activePlayer)
{
	window.draw(m_bgRectangle);

	for (int i = 0; i < m_staticObj.size() ; i++)
	{
		m_staticObj[i]->draw(window);
	}

	for (int i = 0; i < m_players.size(); i++)
	{
		if(i != activePlayer)
			m_players[i]->draw(window);
	}
	m_players[activePlayer]->draw(window);
	
	for (int i = 0; i < m_dwarfs.size(); i++)
	{
		m_dwarfs[i]->draw(window);
	}
}

//-----------------------------------------------------------------

void Board::move(sf::Vector2f direction, sf::Time deltaTime, int activePlayer)
{
	m_players[activePlayer]->move(direction, deltaTime);
	handleCollisions(activePlayer);
	updateBoard();
}

//-----------------------------------------------------------------

void Board::moveDwarfs(sf::Time deltaTime)
{
	for (auto& dwarf : m_dwarfs)
	{
		dwarf->move(deltaTime);
		handleDwarfCollisions();
	}
}

//-----------------------------------------------------------------

bool Board::getEndlevel() const
{
	return m_endLevel;
}

//-----------------------------------------------------------------

int Board::getLevelNum() const
{
	return m_levelNum;
}

//-----------------------------------------------------------------

bool Board::getHasKey()const
{
	return m_hasKey;
}

//-----------------------------------------------------------------

BonusType Board::getBonus() const
{
	return m_bonusType;
}

//-----------------------------------------------------------------

void Board::loadLevel()
{
	m_hasKey = false;
	m_endLevel = false;
	m_levelFile.close();
	
	openLevelFile();
}

//-----------------------------------------------------------------

//return false if finished all levels
bool Board::setLevelNum()
{
	if (m_levelNum < NUM_OF_LEVELS)
	{
		m_levelNum++;
		return true;
	}
	resetLevelNum();
	return false;
}

//-----------------------------------------------------------------

void Board::resetLevelNum()
{
	m_levelNum = 1;
}

//-----------------------------------------------------------------

void Board::removeDwarfs()
{
	m_dwarfs.clear();
}

void Board::moreDwarfs()
{
	bool added = false;
	
	while (!added)
	{
		int row = rand() % m_height;
		int col = 1;

		if(canAddDwarf(row, col))
		{
			addDwarfToRow(row, col);
			added = true;
		}
	}
}

void Board::fastDwarfs()
{
	for (int i = 0; i < m_dwarfs.size(); i++)
	{
		m_dwarfs[i]->increaseSpeed();
	}
}

void Board::slowDwarfs()
{
	for (int i = 0; i < m_dwarfs.size(); i++)
	{
		m_dwarfs[i]->decreaseSpeed();
	}
}

//-----------------------------------------------------------------

void Board::createLevel()
{
	readLevel();
	createObjects();
	initTeleportPartners();
}

void Board::setBonus(BonusType type)
{
	m_bonusType = type;
}

//-----------------------------------------------------------------

void Board::readLevelSize()
{
	m_levelFile.seekg(0);

	int num;
	// reading height
	m_levelFile >> num;
	m_height = num;

	// reading width
	m_levelFile >> num;
	m_width = num;
}

//-----------------------------------------------------------------

void Board::createObjects()
{
	sf::Vector2f position;
	//float xPos, yPos;

	m_staticObj.clear();
	m_players.clear();
	m_dwarfs.clear();

	m_players.resize(NUM_OF_MOVING);

	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			Icons symbol = getSymbol(row, col);
			if (symbol == SPACE)
				continue;

			position = createPosition(row, col, symbol);

			if (isStaticObj(symbol))
				createStatic(symbol, position);
			else
				createMoving(symbol, position);
		}
	}
}

//-----------------------------------------------------------------

bool Board::isStaticObj(Icons symbol)
{
	return (symbol > 4 && symbol < NUM_OF_ICONS);
}

//-----------------------------------------------------------------


void Board::setBgRectangle()
{
	//m_bgRectangle.setFillColor(sf::Color::Color(51, 51, 51));
	m_bgRectangle.setTexture(Resources::instance().getBoardBackground());
}

//-----------------------------------------------------------------

void Board::createMat()
{
	int square_size = ((BOARD_H) / 10) - 10; //set 500 to const
	m_mat = initMat(10, square_size);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			initSquare(i, j, square_size);
			m_mat[i][j].setTexture(NULL);
			m_mat[i][j].setFillColor(sf::Color::White);
		}
	}
}

//-----------------------------------------------------------------

void Board::handleCollisions(int activePlayer)
{
	for (auto& unmovable : m_staticObj)
	{
		if (m_players[activePlayer]->checkColisionWith(*unmovable))
		{
			m_players[activePlayer]->handleCollision(*unmovable);
		}

	}
	for (auto& movable : m_players) //Tali: all moving objects in m_players are players. if we dont care for collsioins we dont need this
	{
		if (m_players[activePlayer]->checkColisionWith(*movable))
		{
			m_players[activePlayer]->handleCollision(*movable);
		}
	}
	for (auto& dwarf : m_dwarfs)
	{
		if (m_players[activePlayer]->checkColisionWith(*dwarf))
		{
			m_players[activePlayer]->handleCollision(*dwarf);
		}
	}
}

//-----------------------------------------------------------------

void Board::handleDwarfCollisions()
{
	for (auto& unmovable : m_staticObj)
	{
		for (int i = 0; i < m_dwarfs.size(); i++)
		{
			if (m_dwarfs[i]->checkColisionWith(*unmovable))
				m_dwarfs[i]->handleCollision(*unmovable);
		}
	}
}

//-----------------------------------------------------------------

void Board::updateBoard()
{
	if (checkEndLevel())
	{
		m_endLevel = true;
		return;
	}
	m_hasKey = checkHasKey();
	changeStatic();
	removeStaticObjects();
}

//-----------------------------------------------------------------

void Board::removeStaticObjects()
{
	std::erase_if(m_staticObj, [](auto& unmovable)
	{
		return unmovable->isDisposed();
	});
}

//-----------------------------------------------------------------

void Board::changeStatic()
{
	sf::Vector2f pos;

	for (auto& unmovable : m_staticObj)
	{
		if (auto staticPtr = dynamic_cast<Orc*>(unmovable.get()))
		{
			if (staticPtr->isDisposed())
			{
				pos = staticPtr->getPosition();
				m_staticObj.emplace_back(std::make_unique<Key>(KEY, pos, m_width, m_height));
			}
		}
		if (auto staticPtr = dynamic_cast<Bonus*>(unmovable.get()))
		{
			if (staticPtr->isDisposed())
			{
				if (typeid(*staticPtr) == typeid(AddTimeBonus))
					m_bonusType = ADDTIME;
				else if (typeid(*staticPtr) == typeid(SubTimeBonus))
					m_bonusType = SUBTIME;
				else if (typeid(*staticPtr) == typeid(RmvDwarfsBonus))
					m_bonusType = RMVDWARFS;
				else if (typeid(*staticPtr) == typeid(MoreDwarfsBonus))
					m_bonusType = MOREDWARFS;
				else if (typeid(*staticPtr) == typeid(SlowDwarfsBonus))
					m_bonusType = SLOWDWARFS;
				else if (typeid(*staticPtr) == typeid(FastDwarfsBonus))
					m_bonusType = FASTDWARFS;
			}
		}
	}
}

//-----------------------------------------------------------------

void Board::initPartners()
{
	int numOfPartners, row1, col1, row2, col2;
	sf::Vector2f position1, position2;

	m_partners.clear();

	m_levelFile >> numOfPartners;

	for (int i = 0; i < numOfPartners; i++)
	{
		m_levelFile >> row1 >> col1 >> row2 >> col2;

		if (row1 != EOF || col1 != EOF || row2 != EOF || col2 != EOF)
			m_partners.push_back(Partners(row1, col1, row2, col2));
	}
}

//-----------------------------------------------------------------

sf::Vector2f Board::createPosition(int row, int col, int symbol)
{
	sf::Vector2f position;
	float xPos, yPos;
	int size = m_width < m_height ? m_height : m_width;
	//int square_size = ((BOARD_H) / size) - 10; //set 500 to const
	int divide_by = symbol == WALL ? 5.5 : 6;
	float w = (float(BOARD_H -30) / size) / divide_by;
	auto square_size = (w * 512 )/ 100;

	
	int col_offsetX = (WINDOW_W - square_size * m_width) / 2;
	int col_offsetY = (BOARD_H - square_size * m_height) / 2;
	xPos = (float)(col * (square_size) + col_offsetX);
	yPos = (float)(row * (square_size) + col_offsetY);
	position = { xPos, yPos };

	return position;
}

//-----------------------------------------------------------------

void Board::initTeleportPartners()
{
	sf::Vector2f pos, partner1, partner2;

	for (int i = 0; i < m_partners.size(); i++)
	{
		partner1 = createPosition(m_partners[i].row1, m_partners[i].col1, TELEPORT);
		partner2 = createPosition(m_partners[i].row2, m_partners[i].col2, TELEPORT);

		for (auto& unmovable : m_staticObj)
		{
			if (auto staticPtr = dynamic_cast<Teleport*>(unmovable.get()))
			{
				pos = staticPtr->getPosition();

				if (pos == partner1)
				{
					staticPtr->setPartner(createPosition(m_partners[i].row2, m_partners[i].col2 + 1, TELEPORT));
				}
				if (pos == partner2)
				{
					staticPtr->setPartner(createPosition(m_partners[i].row1, m_partners[i].col1 + 1, TELEPORT));
				}
			}
		}
	}
}

bool Board::canAddDwarf(int row, int& newcol)
{
	bool assigned = false;

	for (int col = 0; col < m_width; col++)
	{
		Icons symbol = getSymbol(row, col);
		if (symbol == DWARF)
			return false;
		if (symbol != WALL and !assigned)
		{
			newcol = col;
			assigned = true;
		}
	}
	return true;
}

void Board::addDwarfToRow(int row, int col)
{
	sf::Vector2f position = createPosition(row, col , DWARF);

	createMoving(DWARF, position);
}

//-----------------------------------------------------------------

std::unique_ptr<Bonus> Board::selectRandomBonus(sf::Vector2f position)
{
	int bonus;

	if (!m_isCountdown)
		bonus = rand() % (NUM_OF_BONUS_TYPES - 2) + 2;

	else
		bonus = rand() % NUM_OF_BONUS_TYPES;

	switch (bonus)
	{
	case ADDTIME:
		return std::make_unique<AddTimeBonus>(BONUS, position, m_width, m_height);
	case SUBTIME:
		return std::make_unique<SubTimeBonus>(BONUS, position, m_width, m_height);
	case RMVDWARFS:
		return std::make_unique<RmvDwarfsBonus>(BONUS, position, m_width, m_height);
	case MOREDWARFS:
		return std::make_unique<MoreDwarfsBonus>(BONUS, position, m_width, m_height);
	case SLOWDWARFS:
		return std::make_unique<SlowDwarfsBonus>(BONUS, position, m_width, m_height);
	case FASTDWARFS:
		return std::make_unique<FastDwarfsBonus>(BONUS, position, m_width, m_height);
	default:
		break;
	}
	return nullptr;
}

//-----------------------------------------------------------------

void Board::createMoving(Icons symbol, sf::Vector2f position)
{
	switch (symbol)
	{
	case KING:
		m_players[KING] = std::make_unique<King>(symbol, position, m_width, m_height);
		break;
	case WARRIOR:
		m_players[WARRIOR] = std::make_unique<Warrior>(symbol, position, m_width, m_height);
		break;
	case MAGE:
		m_players[MAGE] = std::make_unique<Mage>(symbol, position, m_width, m_height);
		break;
	case THIEF:
		m_players[THIEF] = std::make_unique<Thief>(symbol, position, m_width, m_height);
		break;
	case DWARF:
		m_dwarfs.emplace_back(std::make_unique<Dwarf>(symbol, position, m_width, m_height));
		break;
	default:
		break;
	}
}

//-----------------------------------------------------------------

void Board::createStatic(Icons symbol, sf::Vector2f position)
{
	switch (symbol)
	{
	case WALL:
		m_staticObj.emplace_back(std::make_unique<Wall>(symbol, position, m_width, m_height));
		break;
	case GATE:
		m_staticObj.emplace_back(std::make_unique<Gate>(symbol, position, m_width, m_height));
		break;
	case FIRE:
		m_staticObj.emplace_back(std::make_unique<Fire>(symbol, position, m_width, m_height));
		break;
	case ORC:
		m_staticObj.emplace_back(std::make_unique<Orc>(symbol, position, m_width, m_height));
		break;
	case TELEPORT:
		m_staticObj.emplace_back(std::make_unique<Teleport>(symbol, position, m_width, m_height));
		break;
	case THRONE:
		m_staticObj.emplace_back(std::make_unique<Throne>(symbol, position, m_width, m_height));
		break;
	case KEY:
		m_staticObj.emplace_back(std::make_unique<Key>(symbol, position, m_width, m_height));
		break;
	case BONUS:
		m_staticObj.emplace_back(selectRandomBonus(position));
		break;
	default:
		break;
	}
}

//-----------------------------------------------------------------

std::vector<std::vector<sf::RectangleShape>> Board::initMat(int size, int square_size)
{
	sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
	std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
	return mat;
}

//-----------------------------------------------------------------

void Board::initSquare(int row, int col, int square_size)
{
	int col_offset = (WINDOW_W - BOARD_H) / 2;
	m_mat[row][col].setPosition(col * (square_size + 7) + col_offset, row * (square_size + 7) + 15);
}
