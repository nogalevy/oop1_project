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
	getIcon().move(direction *SPEED_PER_SEC * deltaTime.asSeconds());
}

//-----------------------------------------------------------------

void Player::setActive(bool active)
{
	if (active)
		getIcon().setColor(WHITE_COLOR);
	else
		getIcon().setColor(DARK_PLAYER_COLOR);
}

//-----------------------------------------------------------------

void Player::playSound(const Colision_sound_effect_type type)
{
	m_colisionSounds[type].playMusic(SOUND_EFFECTS_VOLUME);
}

//-----------------------------------------------------------------

void Player::loadPlayerSoundEffects()
{
	for (int i = 0; i < NUM_OF_COLISION_SOUND; i++)
	{
		m_colisionSounds.push_back(Resources::instance().getColisionSoundEffect(Colision_sound_effect_type(i)));
	}
}
