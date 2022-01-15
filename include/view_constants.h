#pragma once 

#include <iostream>
#include <string>

//ENUMS
enum Menu_buttons { START, HELP, EXIT };
enum Board_buttons { VOLUME, HOME };
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


//-----------------------------------------------------------------

//CONST INT: DEFAULT
const int DEFAULT_VOLUME = 10;

//-----------------------------------------------------------------

const int MINUS_ONE = -1;