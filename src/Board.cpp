#include "Board.h"

Board::Board() : m_height(0), m_width(0), rect(sf::Vector2f(30.f, 30.f))
{
	rect.setFillColor(sf::Color::Green);
	m_levelFile.open("Level1.txt", std::ios_base::in);
}

void Board::draw(sf::RenderWindow& window)
{
	window.draw(rect);
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
