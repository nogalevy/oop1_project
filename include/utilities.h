#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>

//const int NUM_OF_MENU_BTNS = 3;
const int NUM_OF_MOVING = 4;
const int NUM_OF_STATIC = 8;
const int NUM_OF_ICONS = NUM_OF_MOVING + NUM_OF_STATIC;
//const int GAME_BTN_NUM = 3;

//enum GameButtons { CLEAR = 12, DELETE = 13, SAVE = 14 };
enum Icons { KING, MAGE, WARRIOR, THIEF, WALL, GATE, FIRE, ORC, TELEPORT, THRONE, KEY, SPACE};

const char SYMBOLS[NUM_OF_ICONS] = { 'K', 'M', 'W', 'T', '=', '#', '*', '!', 'X', '@', 'F', ' ' };
const std::string PLAYERS_NAMES[NUM_OF_MOVING] = { "King", "Mage", "Warrior", "Thief" };

const std::string PIC_NAMES[NUM_OF_ICONS /* + GAME_BTN_NUM*/] = {"king", "wizard", "warrior", "thief", "wall",
											"gate", "fire", "orc", "portal", "throne", "key"/*, "clear", "delete", "save"*/ };

enum timer_type { TIMER = 0, COUNTDOWN };

