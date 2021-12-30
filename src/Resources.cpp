#include "Resources.h"

Resources::Resources()
{
	//load evvverrryyythinngggg
	loadImagesForObjects();
	loadFonts();
}

void Resources::loadImagesForObjects()
{
	sf::Texture image;

	//m_textures.resize(NUM_OF_ICONS - 1);

	for (int i = 0; i < NUM_OF_ICONS - 1; i++)
	{
		image.loadFromFile(PIC_NAMES[i] + ".png");
		m_textures.push_back(image);
	}

}

void Resources::loadFonts()
{
	m_font.loadFromFile("font3.ttf");
}

Resources::~Resources()
{
}

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}


sf::Texture* Resources::getIcon(const Icons symbol)
{
	return &m_textures[symbol];
}

sf::Font* Resources::getFont()
{
	return &m_font;
}
