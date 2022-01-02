#include "Audio.h"

Audio::Audio()
{
	initMusic();
}

Audio::~Audio()
{
}

void Audio::playMusic()
{
	m_sound.play();
	m_sound.setLoop(true);
	m_sound.setVolume(10);
}

void Audio::initMusic()
{
	m_sound.setBuffer(*Resources::instance().getMusic());
}
