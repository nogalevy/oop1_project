#pragma once
#include "MovingObject.h"
#include "Audio.h"

class Player : public MovingObject
{
public:
	Player(Icons symbol, const sf::Vector2f& position,  float objSize);
	virtual ~Player();

	void setPosition(const sf::Vector2f newPosition);
	void move(sf::Vector2f direction, sf::Time deltaTime);// = 0;
	void setActive(bool active);



protected:
	void playSound(const Colision_sound_effect_type type);
private:
	void loadPlayerSoundEffects();
	std::vector <Audio> m_colisionSounds;
};
