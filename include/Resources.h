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
	sf::SoundBuffer* getColisionSoundEffect(const Colision_sound_effect_type type);
	sf::SoundBuffer* getLevelSoundEffect(const Level_sound_effect_type type);
	sf::SoundBuffer* getClickSoundEffect();
	sf::Texture* getVolumeIcon(bool soundOn);
	sf::Texture* getBoardBackground();
	sf::Texture* getHomeBtnTexture();
	sf::Texture* getLevelCompleted();
	sf::Texture* getCongrats();

	sf::Image* getGameIcon();

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
	void loadSoundEffects();
	void loadClickSoundEffect();
	void loadBoardBackground();
	void loadHomeBtnTexture();
	void loadLevelComplete();
	void loadCongrats();
	void loadGameIcon();

	//======Members==========

	//Fonts
	sf::Font m_font;
	sf::Font m_font2;

	//Textures
	std::vector<sf::Texture> m_textures;
	sf::Texture m_menuBackgroundTexture;
	sf::Texture m_helpMenu;
	sf::Texture m_boardBackground;
	std::vector<sf::Texture> m_volumeTextures;
	sf::Texture m_homeBtnTexture;
	sf::Texture m_levelComplete;
	sf::Texture m_congrats;
	
	//Audio
	sf::SoundBuffer m_gameMusic;
	std::vector<sf::SoundBuffer> m_colisionSoundEffectsBuffer;
	std::vector<sf::SoundBuffer> m_levelSoundEffectsBuffer;
	sf::SoundBuffer m_clickSoundEffect;
	
	sf::Image m_gameIcon;
};