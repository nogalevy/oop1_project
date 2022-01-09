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
	//const char* fileName = "Level.txt";

	//createMat();
}

//-----------------------------------------------------------------

Board::~Board()
{
}

//-----------------------------------------------------------------

void Board::readLevel()
{

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
}

//-----------------------------------------------------------------

Icons Board::getSymbol(int row, int col)
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

int Board::getHeight()
{
	return m_height;
}

//-----------------------------------------------------------------

int Board::getWidth()
{
	return m_width;
}

bool Board::checkEndLevel() const
{
	for (auto& movable : m_movingObj)
	{
		//auto movingPtr = movable.get();
		if (auto movablePtr = dynamic_cast<King*>(movable.get()))
		{
			return movablePtr->isReachToThrone();
		}
	}
}

void Board::openLevelFile()
{
	std::string levelName = "Level" + std::to_string(m_levelNum) + ".txt";

	m_levelFile.open(levelName);
	if (!m_levelFile.is_open())
		std::cout << "nope\n";

	readLevel();
	createObjects();
	initTeleportPartners();
}

bool Board::checkHasKey() const
{
	for(auto &movable : m_movingObj)
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


void Board::draw(sf::RenderWindow& window)
{
	window.draw(m_bgRectangle);

	for (int i = 0; i < m_staticObj.size() ; i++)
	{
		m_staticObj[i]->draw(window);
	}
	for (int i = 0; i < m_movingObj.size(); i++)
	{
		m_movingObj[i]->draw(window);
	}
	for (int i = 0; i < m_dwarfs.size(); i++)
	{
		m_dwarfs[i]->draw(window);
	}
}

//-----------------------------------------------------------------

void Board::move(sf::Vector2f direction, sf::Time deltaTime, int activePlayer)
{
	m_movingObj[activePlayer]->move(direction, deltaTime);
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

bool Board::getEndlevel() const
{
	return m_endLevel;
}

int Board::getLevelNum() const
{
	return m_levelNum;
}

bool Board::getHasKey()const
{
	return m_hasKey;
}

void Board::loadNextLevel()
{
	m_hasKey = false;
	m_endLevel = false;
	m_levelFile.close();
	
	openLevelFile();
}

//return false if finished all levels
bool Board::setLevelNum()
{
	if (m_levelNum < NUM_OF_LEVELS)
	{
		m_levelNum++;
		return true;
	}
	m_levelNum = 0;
	return false;

}

//bool Board::getHasKey() const
//{
//	return m_movingObj[THIEF]->getHasKey();
//}

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
	float xPos, yPos;

	m_staticObj.clear();
	m_movingObj.clear();
	m_dwarfs.clear();

	m_movingObj.resize(NUM_OF_MOVING);

	std::cout << "size : " << m_staticObj.size() << std::endl;

	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			Icons symbol = getSymbol(row, col);
			if (symbol == SPACE)
				continue;

			position = createPosition(row, col);

			//Noga: I think we can delete this "if-else" T: you are probably right
			if (isStaticObj(symbol))
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
				{
					m_staticObj.emplace_back(std::make_unique<Teleport>(symbol, position, m_width, m_height));
					/*std::cout << "row: " << row << " col: " << col << "\n";
					std::cout << position.y << " " << position.x << "\n";*/

					break;
				}
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
			else
			{
				switch (symbol)
				{
				case KING:
					m_movingObj[KING] =std::make_unique<King>(symbol, position, m_width, m_height);
					break;
				case WARRIOR:
					m_movingObj[WARRIOR] = std::make_unique<Warrior>(symbol, position, m_width, m_height);
					break;
				case MAGE:
					m_movingObj[MAGE] = std::make_unique<Mage>(symbol, position, m_width, m_height);
					break;
				case THIEF:
					m_movingObj[THIEF] = std::make_unique<Thief>(symbol, position, m_width, m_height);
					break;
				case DWARF:
					m_dwarfs.emplace_back(std::make_unique<Dwarf>(symbol, position, m_width, m_height));
					break;
				default:
					break;
				}
			}
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
	m_bgRectangle.setFillColor(sf::Color::Color(124, 124, 204));
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
		if (m_movingObj[activePlayer]->checkColisionWith(*unmovable))
		{
			/*if (auto staticPtr = dynamic_cast<Teleport*>(unmovable.get()))
			{
				if (m_movingObj[activePlayer])
				{
					pos = staticPtr->getPosition();
				}
			}*/

			m_movingObj[activePlayer]->handleCollision(*unmovable);
		}

	}

	for (auto& movable : m_movingObj)
	{
		if (m_movingObj[activePlayer]->checkColisionWith(*movable))
		{
			m_movingObj[activePlayer]->handleCollision(*movable);
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
		//auto movingPtr = movable.get();
		if (auto staticPtr = dynamic_cast<Orc*>(unmovable.get()))
		{
			if (staticPtr->isDisposed())
			{
				pos = staticPtr->getPosition();
				m_staticObj.emplace_back(std::make_unique<Key>(KEY, pos, m_width, m_height));
			}
		}
	}
}

//-----------------------------------------------------------------

void Board::initPartners()
{
	m_partners.clear();

	int numOfPartners, row1, col1, row2, col2;
	sf::Vector2f position1, position2;

	m_levelFile >> numOfPartners;
	std::cout << numOfPartners << "\n";

	for (int i = 0; i < numOfPartners; i++)
	{
		m_levelFile >> row1 >> col1 >> row2 >> col2;
		std::cout << row1 << col1 << row2 << col2 << "\n";

		if (row1 != EOF || col1 != EOF || row2 != EOF || col2 != EOF)
		{
			position1 = createPosition(row1, col1);
			position2 = createPosition(row2, col2);
			m_partners.push_back(Partners(position1, position2));
		}
	}
}

//-----------------------------------------------------------------

sf::Vector2f Board::createPosition(int row, int col)
{
	sf::Vector2f position;
	float xPos, yPos;

	int square_size = ((BOARD_H) / 10) - 10; //set 500 to const
	int col_offset = (WINDOW_W - BOARD_H) / 2;
	xPos = (float)(col * (square_size + 7) + col_offset);
	yPos = (float)(row * (square_size + 7) + 15);
	position = { xPos, yPos };

	return position;
}

//-----------------------------------------------------------------

void Board::initTeleportPartners()
{
	sf::Vector2f pos;

	for (int i = 0; i < m_partners.size(); i++)
	{
		for (auto& unmovable : m_staticObj)
		{
			if (auto staticPtr = dynamic_cast<Teleport*>(unmovable.get()))
			{
				pos = staticPtr->getPosition();

				if (pos == m_partners[i]._partner1)
				{
					std::cout << "here1\n";
					std::cout << m_partners[i]._partner2.y << " " << m_partners[i]._partner2.x << "\n";
					staticPtr->setPartner(m_partners[i]._partner2);
				}
				else if(pos == m_partners[i]._partner2)
				{
					std::cout << "here2\n";
					std::cout << m_partners[i]._partner1.y << " " << m_partners[i]._partner1.x << "\n";

					staticPtr->setPartner(m_partners[i]._partner1);
				}
			}
		}
	}
}

std::unique_ptr<Bonus> Board::selectRandomBonus(sf::Vector2f position)
{
	int bonus = rand() % NUM_OF_BONUS_TYPES;

	switch (bonus)
	{
	case 0:
		return std::make_unique<AddTimeBonus>(BONUS, position, m_width, m_height);
	case 1:
		return std::make_unique<SubTimeBonus>(BONUS, position, m_width, m_height);
	case 2:
		return std::make_unique<RmvDwarfsBonus>(BONUS, position, m_width, m_height);
	default:
		break;
	}
	return nullptr;
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
