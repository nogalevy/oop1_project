#include "Resources.h"

Resources::Resources()
{
	//load evvverrryyythinngggg
	loadImagesForObjects();
	loadFonts();
	loadMenuBackground();
	loadHelpMenu();
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
	if (!m_font2.loadFromFile("font2.ttf"));
	{

	}
}

void Resources::loadMenuBackground()
{
	if (!m_menuBackgroundTexture.loadFromFile("2.jpg"))
	{
		std::cerr << "error load from file";
	}
}

void Resources::loadHelpMenu()
{
	if (!m_helpMenu.loadFromFile("halp.png"))
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
	if (!m_colisionBuffer.loadFromFile("crash1.ogg"))
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
sf::Font* Resources::getDataFont()
{
	return &m_font2;
}

sf::Texture* Resources::getMenuBackground()
{
	return &m_menuBackgroundTexture;
}

sf::Texture* Resources::getHelpMenu()
{
	return &m_helpMenu;
}

sf::SoundBuffer* Resources::getMusic()
{
	return &m_buffer;;
}

sf::SoundBuffer* Resources::getColisionSound()
{
	return &m_colisionBuffer;;
}