#include "Bonus.h"
//
//Bonus::Bonus()
//{
//}

Bonus::Bonus(Icons symbol, const sf::Vector2f& position,  float objSize)
	: StaticObject(symbol, position,  objSize),
	m_audio(Resources::instance().getBonusSound())
{
}

Bonus::~Bonus()
{
}

void Bonus::playAudio()
{
	m_audio.playMusic(80);
}
