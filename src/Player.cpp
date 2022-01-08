#include "Player.h"


Player::Player(Icons symbol, const sf::Vector2f& position, int mapW, int mapH)
	: MovingObject(symbol, position, mapW, mapH)
{
}

Player::~Player()
{
}


void Player::setPosition(const sf::Vector2f newPosition)
{
	m_icon.setPosition(newPosition);
}

void Player::move(sf::Vector2f direction, sf::Time deltaTime)
{
	m_prevPos = m_icon.getPosition();
	auto speedPerSecond = 100.f;
	m_icon.move(direction * speedPerSecond * deltaTime.asSeconds());
}
