#include "Board.h"
//#include "King.h"


Board::Board() 
	: m_height(0), m_width(0), 
	rect(sf::Vector2f(30.f, 30.f)), 
	/*m_staticObj(WALL, (sf::Vector2f(40.f, 40.f)), m_width, m_height),
	/*m_MOVETEST(KING, (sf::Vector2f(80.f, 80.f)), m_width, m_height),*/
	m_bgRectangle(sf::Vector2f(BOARD_W, BOARD_H))

{
	rect.setFillColor(sf::Color::Green);
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

	//m_movingObj.push_back(std::make_unique<DynamicObject>(KING, position, m_width, m_height));

	window.draw(m_bgRectangle);
	//window.draw(rect);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			//window.draw(m_mat[i][j]);
		}

	//m_staticObj.draw(window);
	//m_MOVETEST.draw(window);

	//m_staticObj[0]->draw(window);
	//m_movingObj[0]->draw(window);

	for (int i = 0; i < m_staticObj.size() ; i++)
	{
		m_staticObj[i]->draw(window);
	}

	for (int i = 0; i < m_movingObj.size(); i++)
	{
		m_movingObj[i]->draw(window);
	}

}

void Board::move(sf::Vector2f direction, sf::Time deltaTime, int activePlayer)
{
	//m_MOVETEST.move(direction, deltaTime);
	
	m_movingObj[activePlayer]->move(direction, deltaTime);

	if (checkCollision(activePlayer))
	{
		std::cout << "Ewww i touched something\n";
			//handleColision(activePlayer);
	}
	
	//moveRect(direction, deltaTime);
	//m_dynamicPlayers[activePlayer].move(direction);

	/*
		in dynamic:
			m_icon-> move(0.f, -m_movementSpeed)
			m_icon-> move(0.f, m_movementSpeed)
			m_icon-> move(m_movementSpeed, 0.f)
			m_icon-> move(-m_movementSpeed, 0.f)
			
	*/
}

void Board::moveRect(sf::Vector2f direction, sf::Time deltaTime)
{
	auto speedPerSecond = 100.f;
	rect.move(direction * speedPerSecond * deltaTime.asSeconds());

	//int m_movementSpeed = 10; // TODO: move to macros
	//switch (dir)
	//{
	//case LEFT:
	//	rect.move(-m_movementSpeed, 0.f); //left
	//	break;
	//case RIGHT:
	//	rect.move(m_movementSpeed, 0.f); //right
	//	break;
	//case UP:
	//	rect.move(0.f, -m_movementSpeed); //up
	//	break;
	//case DOWN:
	//	rect.move(0.f, m_movementSpeed); //down
	//	break;
	//default:
	//	break;
	//}
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

			//Noga: I think we can delete this "if-else" 
			if (isStaticObj(symbol))
			{
				//m_staticObj.emplace_back(std::make_unique<StaticObject>(symbol, position, m_width, m_height));

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
				case PORTAL:
					m_staticObj.emplace_back(std::make_unique<Teleport>(symbol, position, m_width, m_height));
					break;
				case THRONE:
					m_staticObj.emplace_back(std::make_unique<Throne>(symbol, position, m_width, m_height));
					break;
				case KEY:
					m_staticObj.emplace_back(std::make_unique<Key>(symbol, position, m_width, m_height));
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
				default:
					break;
				}
			}
		}
	}

}

bool Board::isStaticObj(Icons symbol)
{
	return (symbol > 3 && symbol < NUM_OF_ICONS);
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

bool Board::checkCollision(int activePlayer)
{
	int i;
	for (i = 0; i < m_movingObj.size(); i++)
	{	
		if(i != activePlayer && m_movingObj[activePlayer]->checkColisionWith(*m_movingObj[i]))
		{
			return true;
		}
	}

	for (i = 0 ; i < m_staticObj.size(); i++)
	{
		if (m_movingObj[activePlayer]->checkColisionWith(*m_staticObj[i]))
		{
			return true;
		}
	}

	return false;
}

std::vector<std::vector<sf::RectangleShape>> Board::initMat(int size, int square_size)
{
	sf::RectangleShape rect1(sf::Vector2f(square_size, square_size));
	std::vector<std::vector<sf::RectangleShape>> mat(size, std::vector<sf::RectangleShape>(size, rect1));
	return mat;
}

void Board::initSquare(int row, int col, int square_size)
{
	//int board_size = BOARD_H;
	int col_offset = (WINDOW_W - BOARD_H) / 2;
	m_mat[row][col].setPosition(col * (square_size + 7) + col_offset, row * (square_size + 7) + 15);
}

/*
sf::Vector2f Board::getPosition(int row, int col)
{
	return m_mat[row][col].getPosition();
}

*/


