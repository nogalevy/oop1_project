//#include <SFML/Graphics.hpp>
#pragma once 

#include <iostream>
#include <string>

enum Menu_buttons { START, HELP, EXIT };
enum Pages { MENU, BOARD };
enum Arrows { LEFT, RIGHT, UP, DOWN };

const std::string TITLE = "Save The King"; //window title

const int WINDOW_W = 1280; //window height
const int WINDOW_H = 870;  //window width

const int BOARD_W = WINDOW_W;
const int BOARD_H = WINDOW_H * 4 / 5;

const int DATA_DISPLAY_W = WINDOW_W;
const int DATA_DISPLAY_H = WINDOW_H / 5;

const float ICON_SIZE = 1048; //before 512