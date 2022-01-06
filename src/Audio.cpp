#include "Audio.h"

Audio::Audio(sf::SoundBuffer* suondBuffer)
{
	initMusic(suondBuffer);
}

Audio::~Audio()
{
}

void Audio::playMusic(bool loop)
{
	m_sound.play();
	m_sound.setLoop(loop);
	m_sound.setVolume(10);
}

void Audio::initMusic(sf::SoundBuffer* suondBuffer)
{
	m_sound.setBuffer(*suondBuffer);
}
