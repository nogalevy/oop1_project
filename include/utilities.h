#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>

const int NUM_OF_LEVELS = 3;
//const int NUM_OF_MENU_BTNS = 3;
const int NUM_OF_MOVING = 4;
const int NUM_OF_STATIC = 8;
const int NUM_OF_ICONS = NUM_OF_MOVING + NUM_OF_STATIC + 1; //1 = dwarfs
//const int GAME_BTN_NUM = 3;
const int NUM_OF_BONUS_TYPES = 6;

//enum GameButtons { CLEAR = 12, DELETE = 13, SAVE = 14 };
enum Icons { KING, MAGE, WARRIOR, THIEF, DWARF, WALL, GATE, FIRE, ORC, TELEPORT, THRONE, KEY, BONUS, SPACE};
enum Additional_icons { THIEF_WITH_KEY = NUM_OF_ICONS};
const char SYMBOLS[NUM_OF_ICONS + 1] = { 'K', 'M', 'W', 'T', '^', '=', '#', '*', '!', 'X', '@', 'F', '$', ' '};
const std::string PLAYERS_NAMES[NUM_OF_MOVING] = { "King", "Mage", "Warrior", "Thief" };

const std::string PIC_NAMES[NUM_OF_ICONS + 1] = { "king.png", "wizard.png", "warrior.png", "thief.png", "dwarf.png", "wall.png",
											"gate.png", "fire.png", "orc.png", "teleport.png", "throne.png", "key.png", "gift.png",
											"thief_with_key.png" };

const int VOLUME_ICON_NUM = 2;
enum volume { OFF = 0, ON = 1 };
const std::string VOLUME_ICON[VOLUME_ICON_NUM] = { "mute_white.png", "volume_white.png" };

enum timer_type { TIMER = 0, COUNTDOWN };

struct Partners {
	int row1, col1,
		row2, col2;
};

enum BonusType {ADDTIME, SUBTIME, RMVDWARFS, MOREDWARFS, SLOWDWARFS, FASTDWARFS, NONE};

const int NUM_OF_COLISION_SOUND = 4;
const int NUM_OF_GAME_SOUND = 2;
const int NUM_OF_SOUND_EFFECTS = NUM_OF_COLISION_SOUND + NUM_OF_GAME_SOUND;

enum Sound_effect_type { DEFAULT_COLISION, WARRIOR_ORC_COLISION, BONUS_COLISION, NO, END_LEVEL, LOSE_LEVEL };
const std::string SOUND_EFFECTS[NUM_OF_SOUND_EFFECTS] = { "colision.ogg", "sword.ogg", "bonus.ogg", "no.ogg", "win.ogg", "loser.ogg"};
