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
	getIcon().setPosition(newPosition);
}

void Player::move(sf::Vector2f direction, sf::Time deltaTime)
{
	m_prevPos = getIcon().getPosition();
	auto speedPerSecond = 100.f;
	getIcon().move(direction * speedPerSecond * deltaTime.asSeconds());
}
