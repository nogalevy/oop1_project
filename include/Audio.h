#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Resources.h"



class Audio {
public:
	Audio(sf::SoundBuffer* soundBuffer);
	~Audio();


	void playMusic(bool loop = false);
	void stopPlayMusic();
private:
	//functions
	void initMusic(sf::SoundBuffer* soundBuffer);

	//members
	//sf::SoundBuffer m_audio; //works like texture to load sound
	sf::Sound m_sound; //for use of small sounds like collisions and such
	//sf::Music m_music; //for use of long term sounds like background music (also allows looping of music)
};