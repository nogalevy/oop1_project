#pragma once

#include "view_constants.h"
#include "Audio.h"
#include "Menu.h"
#include "Board.h"
#include "DataDisplay.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

//#include <conio.h>


//sf::VideoMode window_size = sf::VideoMode(1280, 870);
//sf::Vector2f bg_size = sf::Vector2f(1280.f, 870.f);


class Window {
public:
	Window();
	~Window();
	void startGame();
	void draw() const;
	void drawCurrPage();
	void handleClick(const sf::Event& event);
	void isKeyPressed();
	void handleMenuClick(const sf::Event& event);
	void handleHover(const sf::Vector2f location);
	void resetClock();
private:

	void handleBoardEvent(const sf::Event& event);
	void handleMenuEvent(const sf::Event& event);
	void handleKeyboardClick();
	void movePlayer();
	void moveDwarfs();
	void updateGameData();

	//window
	sf::RenderWindow m_window;

	Audio m_audio;
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

	int m_currPage;
	int m_activePlayer;
	sf::Clock m_timer;
	
	//#fontexample		
	//sf::Font m_font;

};