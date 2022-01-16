#pragma once 

#include <iostream>
#include <string>

//ENUMS
enum Menu_buttons { START, HELP, EXIT };
enum Board_buttons { VOLUME, HOME, RETRY};
enum Pages { MENU, BOARD, HELPMENU, LEVELCOMPLETE, CONGRATS };
enum Arrows { LEFT, RIGHT, UP, DOWN };

//-----------------------------------------------------------------

//OBJECT NAME
const std::string TITLE = "Save The King"; //window title

//-----------------------------------------------------------------

//CONST INT: SIZES
const int WINDOW_W = 1300; //window width
const int WINDOW_H = 900;  //window height

const int BOARD_W = WINDOW_W;
const int BOARD_H = WINDOW_H * 6 / 7;

const int DATA_DISPLAY_W = WINDOW_W;
const int DATA_DISPLAY_H = WINDOW_H / 7;

const float ICON_SIZE = 512;
const int MENU_FONT_SIZE = 65; 
const int DATA_DISPLAY_FONT_SIZE = 30;
const int MARGIN = 10;
const int DATA_DISPLAY_POS_Y = BOARD_H + MARGIN;

//-----------------------------------------------------------------

//CONST INT/FLOAT: DEFAULT
//sound
const int DEFAULT_VOLUME = 10;
const int SOUND_EFFECTS_VOLUME = 20;

//bonus
const int ADD_TIME_SEC = 20;
const int SUB_TIME_SEC = -10;

//speed
const float SPEED_PER_SEC = 100.f;
const float MIN_SPEED = 50.f;
const float MAX_SPEED = 400.f;

//-----------------------------------------------------------------

//CONST INT: DIRECTIONS
const int LEFTD = -1;
const int RIGHTD = 1;

//-----------------------------------------------------------------

const int MINUS_ONE = -1;

