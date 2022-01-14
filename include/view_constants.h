//#include <SFML/Graphics.hpp>
#pragma once 

#include <iostream>
#include <string>

enum Menu_buttons { START, HELP, EXIT };
enum Board_buttons { VOLUME, HOME };
enum Pages { MENU, BOARD, HELPMENU, LEVELCOMPLETE, CONGRATS };
enum Arrows { LEFT, RIGHT, UP, DOWN };

const std::string TITLE = "Save The King"; //window title

const int WINDOW_W = 1300; //window width
const int WINDOW_H = 900;  //window height

const int BOARD_W = WINDOW_W;
const int BOARD_H = WINDOW_H * 6 / 7;

const int DATA_DISPLAY_W = WINDOW_W;
const int DATA_DISPLAY_H = WINDOW_H / 7;

const float ICON_SIZE = 1048; //before 512

const int DEFAULT_VOLUME = 10;
