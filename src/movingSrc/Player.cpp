#include "movingInclude/Player.h"


Player::Player(Icons symbol, const sf::Vector2f& position,  float objSize)
	: MovingObject(symbol, position,  objSize)
{
	loadPlayerSoundEffects();
}

//-----------------------------------------------------------------

void Player::setPosition(const sf::Vector2f newPosition)
{
	getIcon().setPosition(newPosition);
}

//-----------------------------------------------------------------

void Player::move(sf::Vector2f direction, sf::Time deltaTime)
{
	getPrevPos() = getPosition();
	auto speedPerSecond = 100.f;
	getIcon().move(direction * speedPerSecond * deltaTime.asSeconds());
}

//-----------------------------------------------------------------

void Player::setActive(bool active)
{
	if (active)
		getIcon().setColor(WHITE_COLOR);
	else
		getIcon().setColor(sf::Color(196, 194, 194));
}

//-----------------------------------------------------------------

void Player::playSound(const Colision_sound_effect_type type)
{
	m_colisionSounds[type].playMusic(20);
}

//-----------------------------------------------------------------

void Player::loadPlayerSoundEffects()
{
	for (int i = 0; i < NUM_OF_COLISION_SOUND; i++)
	{
		m_colisionSounds.push_back(Resources::instance().getColisionSoundEffect(Colision_sound_effect_type(i)));
	}
}
