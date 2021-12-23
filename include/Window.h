#pragma once

#include "view_constants.h"

#include "Menu.h"
#include "Board.h"
#include "DataDisplay.h"

#include <SFML/Graphics.hpp>


//sf::VideoMode window_size = sf::VideoMode(1280, 870);
//sf::Vector2f bg_size = sf::Vector2f(1280.f, 870.f);


class Window {
public:
	Window();
	void startGame();
	void draw() const;

private:
	//window
	sf::RenderWindow m_window;
	//menu - first page
	Menu m_menu;
	//board game
	Board m_board;
	// data bar (under the board)
	DataDisplay m_dataDisplay;
	//game icon
	sf::Image m_image;
	//game background
	sf::Texture m_bgTexture;

};