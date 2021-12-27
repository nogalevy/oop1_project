#pragma once

#include <SFML/Graphics.hpp>

const int NUM_OF_MENU_BTNS = 3;
const int NUM_OF_ICONS = 11;
//const int GAME_BTN_NUM = 3;

//enum GameButtons { CLEAR = 11, DELETE = 12, SAVE = 13 };
enum Icons { KING, MAGE, WARRIOR, THIEF, WALL, GATE, FIRE, ORC, PORTAL, THRONE, KEY };

const char SIMBOLS[NUM_OF_ICONS] = { 'K', 'M', 'W', 'T', '=', '#', '*', '!', 'X', '@', 'F' };

const std::string PIC_NAMES[NUM_OF_ICONS /* + GAME_BTN_NUM*/] = {"king", "wizard", "warrior", "thief", "brickwall_2",
											"gate", "fire", "orc", "portal", "throne", "key"/*, "clear", "delete", "save"*/ };

std::vector<sf::Texture> m_textures;


void initTextures()
{
	m_textures.resize(NUM_OF_ICONS);
	for (int i = 0; i < NUM_OF_ICONS; i++)
	{
		m_textures[i].loadFromFile(PIC_NAMES[i] + ".png");
		m_textures[i].setSmooth(true);
	}
}