#include "Board.h"

Board::Board(int width, int height)
	: rect(sf::Vector2f(30.f, 30.f))
{
	rect.setFillColor(sf::Color::Green);
}

void Board::draw(sf::RenderWindow& window)
{
	window.draw(rect);
}

void Board::move(int direction, int activePlayer)
{
	moveRect(direction);
	//m_dynamicPlayers[activePlayer].move(direction);

	/*
		in dynamic:
			m_icon-> move(0.f, -m_movementSpeed)
			m_icon-> move(0.f, m_movementSpeed)
			m_icon-> move(m_movementSpeed, 0.f)
			m_icon-> move(-m_movementSpeed, 0.f)
			
	*/
}

void Board::moveRect(int dir)
{
	int m_movementSpeed = 10; // TODO: move to macros
	switch (dir)
	{
	case LEFT:
		rect.move(-m_movementSpeed, 0.f); //left
		break;
	case RIGHT:
		rect.move(m_movementSpeed, 0.f); //right
		break;
	case UP:
		rect.move(0.f, -m_movementSpeed); //up
		break;
	case DOWN:
		rect.move(0.f, m_movementSpeed); //down
		break;
	default:
		break;
	}
}
