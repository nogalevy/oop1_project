#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>

const int NUM_OF_ICONS = 12;
//const int GAME_BTN_NUM = 3;

//enum GameButtons { CLEAR = 11, DELETE = 12, SAVE = 13 };
enum Icons { KING, MAGE, WARRIOR, THIEF, WALL, GATE, FIRE, ORC, PORTAL, THRONE, KEY, SPACE};

const char SYMBOLS[NUM_OF_ICONS] = { 'K', 'M', 'W', 'T', '=', '#', '*', '!', 'X', '@', 'F', ' '};

const std::string PIC_NAMES[NUM_OF_ICONS /* + GAME_BTN_NUM*/] = {"king", "wizard", "warrior", "thief", "brickwall_2",
											"gate", "fire", "orc", "portal", "throne", "key"/*, "clear", "delete", "save"*/ };

/*
std::vector<sf::Texture> textures;

void initTextures()
{
	textures.resize(NUM_OF_ICONS - 1);
	for (int i = 0; i < NUM_OF_ICONS - 1; i++)
	{
		textures[i].loadFromFile(PIC_NAMES[i] + ".png");
			//std::cout << "help\n";
		
		//textures[i].setSmooth(true);
	}
}*/