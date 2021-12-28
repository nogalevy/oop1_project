#include "Board.h"

Board::Board(	) : m_height(0), m_width(0), rect(sf::Vector2f(30.f, 30.f))
{
	//rect.setFillColor(sf::Color::Green);
	//m_levelFile.open("Level1.txt", std::ios_base::in);
	//readLevel();
	createObjects();
}

Board::~Board()
{
}

void Board::draw(sf::RenderWindow& window)
{
	sf::Vector2f position;
	float xPos, yPos;

	xPos = ((float)WINDOW_W / (float)(m_width) * 5);
	yPos = ((float)WINDOW_H / (float)(m_height) * 5);
	position = { xPos, yPos };

	m_staticObj.push_back(std::make_unique<StaticObject>(WALL, position, m_width, m_height));

	xPos = ((float)WINDOW_W / (float)(m_width) * 7);
	yPos = ((float)WINDOW_H / (float)(m_height) * 7);
	position = { xPos, yPos };

	m_movingObj.push_back(std::make_unique<DynamicObject>(KING, position, m_width, m_height));


	/*
	//window.draw(rect);
	m_staticObj[0]->draw(window);
	m_movingObj[0]->draw(window);
}

void Board::move(sf::Vector2f direction, sf::Time deltaTime, int activePlayer)
{
	moveRect(direction, deltaTime);
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
	std::string number;

	// reading height
	m_levelFile >> number;
	m_height = std::stoi(number, nullptr);

	// reading width
	m_levelFile >> number;
	m_width = std::stoi(number, nullptr);
}

void Board::createObjects()
{
	//Icons symbol;
	/*sf::Vector2f position;
	float xPos, yPos;
	
	xPos = ((float)WINDOW_W / (float)(m_width)*5);
	yPos = ((float)WINDOW_H / (float)(m_height)*5);
	position = { xPos, yPos };

	m_staticObj.push_back(std::make_unique<StaticObject>(WALL, position, m_width, m_height));

	xPos = ((float)WINDOW_W / (float)(m_width)*7);
	yPos = ((float)WINDOW_H / (float)(m_height)*7);
	position = { xPos, yPos };

	m_movingObj.push_back(std::make_unique<DynamicObject>(KING, position, m_width, m_height));*/


	/*
	for (int row = 0; row < m_height; row++)
	{
		for (int col = 0; col < m_width; col++)
		{
			symbol = getSymbol(row, col);
			if (symbol == SPACE)
				continue;
			xPos = ((float)WINDOW_W / (float)(m_width) * col);
			yPos = ((float)WINDOW_H / (float)(m_height) * row);
			position = { xPos, yPos };

			if (isStaticObj(symbol))
			{
				//std::unique_ptr<Wall> staticObj = std::make_unique<Wall>(symbol, position, m_width, m_height);
				m_staticObj.push_back(std::make_unique<Wall>(symbol, position, m_width, m_height));
			}
			else 
			{
				std::unique_ptr<King> dynObj = std::make_unique<King>(symbol, position, m_width, m_height);
				m_movingObj.push_back(dynObj);
				return; //for now 

			}
		}
	}*/
}

bool Board::isStaticObj(Icons symbol)
{
	return (symbol > 3 && symbol < NUM_OF_ICONS);
}
