#include "Board.h"


Board::Board() 
	: m_height(0), m_width(0),  
	m_bgRectangle(sf::Vector2f(BOARD_W, BOARD_H))
{
	setBgRectangle();	

	//const char* fileName = "Level.txt";
	m_levelFile.open("Level.txt");
	if (!m_levelFile.is_open())
		std::cout << "nope\n";

	readLevel();
	createObjects();
	//createMat();
	
}

Board::~Board()
{
}

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

void Board::move(sf::Vector2f direction, sf::Time deltaTime, int activePlayer)
{
	m_movingObj[activePlayer]->move(direction, deltaTime);
	handleCollisions(activePlayer);
	updateBoard();
}


void Board::readLevel()
{
	readLevelSize();
	char c;

	m_levelFile.get(c);

	auto line = std::string();
	for (int row = 0; row < m_height; row++)
	{
		getline(m_levelFile, line);
		m_boardMat.push_back(line);
	}
}

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

int Board::getHeight()
{
	return m_height;
}


int Board::getWidth()
{
	return m_width;
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

void Board::moveDwarfs()
{
	for (auto& dwarf : m_dwarfs)
	{
		//dwarf->sayHello();
	}
}

bool Board::getHasKey()const
{
	return m_hasKey;
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

void Board::createObjects()
{
	sf::Vector2f position;
	float xPos, yPos;
	
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			Icons symbol = getSymbol(row, col);
			if (symbol == SPACE)
				continue;
			
			int square_size = ((BOARD_H) / 10) - 10; //set 500 to const
			int col_offset = (WINDOW_W - BOARD_H) / 2;
			xPos = (float)(col * (square_size + 7) + col_offset);
			yPos = (float)(row * (square_size + 7) + 15);
			position = { xPos, yPos };

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
					m_staticObj.emplace_back(std::make_unique<Teleport>(symbol, position, m_width, m_height));
					break;
				case THRONE:
					m_staticObj.emplace_back(std::make_unique<Throne>(symbol, position, m_width, m_height));
					break;
				case KEY:
					m_staticObj.emplace_back(std::make_unique<Key>(symbol, position, m_width, m_height));
					break;
				case BONUS:
					m_staticObj.emplace_back(std::make_unique<AddTimeBonus>(symbol, position, m_width, m_height));
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
					m_movingObj.emplace_back(std::make_unique<King>(symbol, position, m_width, m_height));
					break;
				case WARRIOR:
					m_movingObj.emplace_back(std::make_unique<Warrior>(symbol, position, m_width, m_height));
					break;
				case MAGE:
					m_movingObj.emplace_back(std::make_unique<Mage>(symbol, position, m_width, m_height));
					break;
				case THIEF:
					m_movingObj.emplace_back(std::make_unique<Thief>(symbol, position, m_width, m_height));
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

bool Board::isStaticObj(Icons symbol)
{
	return (symbol > 4 && symbol < NUM_OF_ICONS);
}

void Board::setBgRectangle()
{
	m_bgRectangle.setFillColor(sf::Color::Color(142, 204, 124));
}

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

void Board::handleCollisions(int activePlayer)
{
	for (auto& unmovable : m_staticObj)
	{
		if (m_movingObj[activePlayer]->checkColisionWith(*unmovable))
		{
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

void Board::updateBoard()
{
	m_hasKey = checkHasKey();
	changeStatic();
	removeStaticObjects();
}

void Board::removeStaticObjects()
{
	std::erase_if(m_staticObj, [](auto& unmovable)
	{
		return unmovable->isDisposed();
	});
}

void Board::changeStatic()
{
	sf::Vector2f pos;

	for (auto& unmovable : m_staticObj)
	{
		//auto movingPtr = movable.get();
		if (auto staticPtr = dynamic_cast<Orc*>(unmovable.get()))
		{
			if (staticPtr->getIsDied())
			{
				pos = staticPtr->getPosition();
				m_staticObj.emplace_back(std::make_unique<Key>(KEY, pos, m_width, m_height));
			}
		}
	}
}

std::vector<std::vector<sf::RectangleShape>> Board::initMat(int size, int square_size)
{
	sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
	std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
	return mat;
}

void Board::initSquare(int row, int col, int square_size)
{
	int col_offset = (WINDOW_W - BOARD_H) / 2;
	m_mat[row][col].setPosition(col * (square_size + 7) + col_offset, row * (square_size + 7) + 15);
}

