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

	sf::Texture* getIcon(const Icons symbol);
	sf::Font* getFont();
	sf::Texture* getMenuBackground();
	sf::SoundBuffer* getMusic();

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadImagesForObjects();
	void loadFonts();
	void loadMenuBackground();
	void loadAudio();

	//Members
	std::vector<sf::Texture> m_textures;
	sf::Font m_font;
	sf::Texture m_menuBackgroundTexture;
	sf::SoundBuffer m_buffer;


};