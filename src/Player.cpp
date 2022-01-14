#include "Player.h"


Player::Player(Icons symbol, const sf::Vector2f& position,  float objSize)
	: MovingObject(symbol, position,  objSize)
{
	loadPlayerSoundEffects();
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

void Player::playSound(const int type)
{
	m_colisionSounds[type].playMusic(20);
}

void Player::loadPlayerSoundEffects()
{
	for (int i = 0; i < NUM_OF_COLISION_SOUND; i++)
	{
		m_colisionSounds.push_back(Resources::instance().getColisionSoundEffect(i));
	}
}

void Player::setActive(bool active)
{
	if (active)
		getIcon().setColor(sf::Color::White);
	else
		getIcon().setColor(sf::Color(124, 124, 124));
}