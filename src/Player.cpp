#include "Player.h"


Player::Player(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH)
	//,m_prevPos(position)
{
}

Player::~Player()
{
}


void Player::move(sf::Vector2f direction, sf::Time deltaTime)
{
	m_prevPos = m_icon.getPosition();
	auto speedPerSecond = 100.f;
	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
}
//
//void Player::moveToPrevPos()
//{
//	m_icon.setPosition(m_prevPos);
//}
