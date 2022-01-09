#include "Audio.h"

Audio::Audio(sf::SoundBuffer* soundBuffer)
{
	initMusic(soundBuffer);
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

void Audio::initMusic(sf::SoundBuffer* soundBuffer)
{
	m_sound.setBuffer(*soundBuffer);
}
