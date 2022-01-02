#include "Resources.h"

Resources::Resources()
{
	//load evvverrryyythinngggg
	loadImagesForObjects();
	loadFonts();
	loadMenuBackground();
	loadAudio();
}

void Resources::loadImagesForObjects()
{
	sf::Texture image;

	//m_textures.resize(NUM_OF_ICONS - 1);

	for (int i = 0; i < NUM_OF_ICONS - 1; i++)
	{
		if (!image.loadFromFile(PIC_NAMES[i] + ".png"))
		{
			std::cerr << "error load from file";
		}
		m_textures.push_back(image);
	}
}

void Resources::loadFonts()
{
	if (!m_font.loadFromFile("font3.ttf"))
	{
		std::cerr << "error load from file";
	}
}

void Resources::loadMenuBackground()
{
	if (!m_menuBackgroundTexture.loadFromFile("2.jpg"))
	{
		std::cerr << "error load from file";
	}
}

void Resources::loadAudio()
{
	std::cout << "hello\n";
	if (!m_buffer.loadFromFile("toward-the-mountains.ogg"))
	{
		std::cerr << "error load from file";
	}
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

sf::Texture* Resources::getMenuBackground()
{
	return &m_menuBackgroundTexture;
}

sf::SoundBuffer* Resources::getMusic()
{
	return &m_buffer;;
}
