#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "utilities.h"
#include <SFML/Audio.hpp>
 

class Resources
{
public:
	~Resources();
	static Resources& instance();

	//Access Functions

	sf::Texture* getIcon(const int symbol);
	sf::Font* getFont();
	sf::Font* getDataFont();
	sf::Texture* getMenuBackground();
	sf::Texture* getHelpMenu();
	sf::SoundBuffer* getMusic();
	sf::SoundBuffer* getBonusSound();
	sf::SoundBuffer* getColisionSoundEffect(const int type);
	sf::SoundBuffer* getLevelSoundEffect(const int type);
	sf::Texture* getVolumeIcon(bool soundOn);
	sf::Texture* getBoardBackground();
	sf::Texture* getHomeBtnTexture();
	sf::Texture* getLevelCompleted();
	sf::Texture* getCongrats();
private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadImagesForObjects();
	void loadFonts();
	void loadMenuBackground();
	void loadHelpMenu();
	void loadVolumeIcons();
	void loadAudio();
	void loadBonusAudio();
	void loadSoundEffects();
	void loadBoardBackground();
	void loadHomeBtnTexture();
	void loadLevelComplete();
	void loadCongrats();

	//Members
	std::vector<sf::Texture> m_textures;
	sf::Font m_font;
	sf::Font m_font2;
	sf::Texture m_menuBackgroundTexture;
	sf::Texture m_helpMenu;
	sf::Texture m_boardBackground;
	std::vector<sf::Texture> m_volumeTextures;
	sf::Texture m_homeBtnTexture;
	
	sf::SoundBuffer m_gameMusic;
	sf::SoundBuffer m_bonusBuffer;
	std::vector<sf::SoundBuffer> m_colisionSoundEffectsBuffer;
	std::vector<sf::SoundBuffer> m_levelSoundEffectsBuffer;
	
	sf::Texture m_levelComplete;
	sf::Texture m_congrats;

};