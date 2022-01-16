#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>

//CONST INT: NUM OF
const int NUM_OF_LEVELS = 3;
const int NUM_OF_MOVING = 4;
const int NUM_OF_STATIC = 8;
const int NUM_OF_ICONS = NUM_OF_MOVING + NUM_OF_STATIC + 1; //1 = dwarfs
const int NUM_OF_BONUS_TYPES = 6;
const int NUM_OF_COLISION_SOUND = 7;
const int NUM_OF_LEVEL_SOUND = 2;
const int NUM_OF_MENU_BTNS = 3;
const int VOLUME_ICON_NUM = 2;

//-----------------------------------------------------------------

//ENUMS
enum Icons { KING, MAGE, WARRIOR, THIEF, DWARF, WALL, GATE, FIRE, ORC, TELEPORT, THRONE, KEY, BONUS, SPACE};
enum Additional_icons { THIEF_WITH_KEY = NUM_OF_ICONS};
enum volume { OFF = 0, ON = 1 };
enum timer_type { TIMER = 0, COUNTDOWN };
enum BonusType {ADDTIME, SUBTIME, RMVDWARFS, MOREDWARFS, SLOWDWARFS, FASTDWARFS, NONE};
enum Colision_sound_effect_type { DEFAULT_COLISION, WARRIOR_ORC_COLISION, BONUS_COLISION, TELEPORT_COLISION,
									THIEF_GATE_COLISION, MAGE_FIRE_COLISION, DWARF_COLISION };
enum Level_sound_effect_type { END_LEVEL, LOSE_LEVEL };

//-----------------------------------------------------------------

//OBJECT NAMES AND FILE SYMBOLS
const char SYMBOLS[NUM_OF_ICONS + 1] = { 'K', 'M', 'W', 'T', '^', '=', '#', '*', '!', 'X', '@', 'F', '$', ' '};
const std::string PLAYERS_NAMES[NUM_OF_MOVING] = { "King", "Mage", "Warrior", "Thief" };
const std::string BTN_TEXT[NUM_OF_MENU_BTNS] = { "Start", "Help", "Exit" }; //menu buttons text

//-----------------------------------------------------------------

//FILE NAMES
const std::string PIC_NAMES[NUM_OF_ICONS + 1] = { "king.png", "wizard.png", "warrior.png", "thief.png", "dwarf.png", "wall.png",
											"gate.png", "fire.png", "orc.png", "teleport.png", "throne.png", "key.png", "gift.png",
											"thief_with_key.png" };
const std::string VOLUME_ICON[VOLUME_ICON_NUM] = { "mute_white.png", "volume_white.png" };
const std::string COLISION_SOUND_EFFECTS[NUM_OF_COLISION_SOUND] = { "colision.ogg", "sword.ogg", "bonus.ogg" ,"teleport.ogg",
																	"gate.ogg", "fire.ogg", "dwarf.ogg"};
const std::string LEVEL_SOUND_EFFECTS[NUM_OF_LEVEL_SOUND] = { "win.ogg", "loser.ogg" };

//-----------------------------------------------------------------

//STRUCT
struct Partners {
	int row1, col1,
		row2, col2;
};


//-----------------------------------------------------------------
//CONST COLORS

const sf::Color WHITE_COLOR = sf::Color::Color(252, 252, 252);
const sf::Color HOVER_MENU_BTN_COLOR = sf::Color::Color(239, 236, 10);
const sf::Color DATA_DISPLAY_BACKGROUMD_COLOR = sf::Color::Color(26, 26, 26);




