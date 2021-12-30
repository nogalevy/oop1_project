#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "utilities.h"

class Resources
{
public:
	~Resources();
	static Resources& instance();

	//Access Functions

	sf::Texture* getIcon(const Icons symbol);
	sf::Font* getFont();

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadImagesForObjects();
	void loadFonts();

	//Members
	std::vector<sf::Texture> m_textures;
	sf::Font m_font;

};