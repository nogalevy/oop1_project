#include "Resources.h"

Resources::Resources()
{
	//load evvverrryyythinngggg
	loadImagesForObjects();
	loadFonts();
	loadMenuBackground();
	loadHelpMenu();
	loadAudio();
	loadSoundEffects();
	loadVolumeIcons();
	loadBoardBackground();
	loadHomeBtnTexture();
	loadLevelComplete();
}

//-----------------------------------------------------------------

void Resources::loadImagesForObjects()
{
	sf::Texture image;

	//m_textures.resize(NUM_OF_ICONS - 1);

	for (int i = 0; i < NUM_OF_ICONS + 1; i++)
	{
		if (!image.loadFromFile(PIC_NAMES[i]))
		{
			std::cerr << "error load from icons file, image:" << i;
		}
		m_textures.push_back(image);
	}
}

//-----------------------------------------------------------------

void Resources::loadFonts()
{
	if (!m_font.loadFromFile("YatraOne.ttf"))
	{
		std::cerr << "error load from file";
	}
	if (!m_font2.loadFromFile("font2.ttf"))
	{
		std::cerr << "error load from file";
	}
}

//-----------------------------------------------------------------

void Resources::loadMenuBackground()
{
	if (!m_menuBackgroundTexture.loadFromFile("menu_bg.png"))
	{
		std::cerr << "error load from file";
	}
}

//-----------------------------------------------------------------

void Resources::loadHelpMenu()
{
	if (!m_helpMenu.loadFromFile("halp.png"))
	{
		std::cerr << "error load from file";
	}
}

void Resources::loadVolumeIcons()
{
	sf::Texture image;

	for (int i = 0; i < VOLUME_ICON_NUM; i++)
	{
		if (!image.loadFromFile(VOLUME_ICON[i]))
		{
			std::cerr << "error load from file";
		}
		m_volumeTextures.push_back(image);
	}
}

//-----------------------------------------------------------------

void Resources::loadAudio()
{
	std::cout << "hello\n";
	if (!m_gameMusic.loadFromFile("toward-the-mountains.ogg"))
	{
		std::cerr << "error load from file";
	}
}

void Resources::loadSoundEffects()
{
	sf::SoundBuffer buff;

	for (int i = 0; i < NUM_OF_SOUND_EFFECTS; i++)
	{
		if (!buff.loadFromFile(SOUND_EFFECTS[i]))
		{
			std::cerr << "error load audio from file";
		}
		m_soundEffectsBuffer.push_back(buff);
	}
}

void Resources::loadBoardBackground()
{
	if (!m_boardBackground.loadFromFile("board_bg.jpg"))
	{
		std::cerr << "error load from file";
	}
}

void Resources::loadHomeBtnTexture()
{
	if (!m_homeBtnTexture.loadFromFile("home.png"))
	{
		std::cerr << "error load from file";
	}
}

void Resources::loadLevelComplete()
{
	if (!m_levelComplete.loadFromFile("levelcompleted.png"))
	{
		std::cerr << "error load from file";
	}
}

//-----------------------------------------------------------------

Resources::~Resources()
{
}

//-----------------------------------------------------------------

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}

//-----------------------------------------------------------------

sf::Texture* Resources::getIcon(const int symbol)
{
	return &m_textures[symbol];
}

//-----------------------------------------------------------------

sf::Font* Resources::getFont()
{
	return &m_font;
}

//-----------------------------------------------------------------

sf::Font* Resources::getDataFont()
{
	return &m_font2;
}

//-----------------------------------------------------------------

sf::Texture* Resources::getMenuBackground()
{
	return &m_menuBackgroundTexture;
}

//-----------------------------------------------------------------

sf::Texture* Resources::getHelpMenu()
{
	return &m_helpMenu;
}

//-----------------------------------------------------------------

sf::SoundBuffer* Resources::getMusic()
{
	return &m_gameMusic;;
}

//-----------------------------------------------------------------

sf::SoundBuffer* Resources::getSoundEffect(const int type)
{
	return &m_soundEffectsBuffer[type];
}

sf::Texture* Resources::getVolumeIcon(bool soundOn)
{
	return (soundOn ? &m_volumeTextures[ON] : &m_volumeTextures[OFF]);
}

sf::Texture* Resources::getBoardBackground()
{
	return &m_boardBackground;;
}

sf::Texture* Resources::getHomeBtnTexture()
{
	return &m_homeBtnTexture;
}

sf::Texture* Resources::getLevelCompleted()
{
	return &m_levelComplete;
}
