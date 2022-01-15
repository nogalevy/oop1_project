#pragma once

#include "view_constants.h"
#include "Audio.h"
#include "Menu.h"
#include "Board.h"
#include "DataDisplay.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class Controller {
public:
	Controller();
	~Controller();

	void startGame();

private:
	void drawCurrPage();

	//Handle Events
	void handleClick(const sf::Event& event);
	void handleMenuClick(const sf::Event& event);
	void handleBoardClick(const sf::Event& event);
	void handleHover(const sf::Vector2f location);
	void handleNextLevel();
	void handleBoardEvent(const sf::Event& event);
	void handleMenuEvent(const sf::Event& event);
	void handleHelpEvent(const sf::Event& event);
	void handleLevelComplete(const sf::Event& event);
	void handleCongrats(const sf::Event& event);
	void handleKeyboardClick();
	void playClickSound();
	

	//Reset Functions
	void resetClock();
	void resetCurrLevelData();

	//Init Functions
	void setGameIcon();
	void initPages();
	void setSound();

	//Game Functions
	void movePlayer(sf::Time);
	void moveDwarfs(sf::Time);
	void updateGameData();
	void applyBonus();
	void checkLoseLevel();
	void retryLevel();

	//======Members==========

	sf::RenderWindow m_window;

	Audio m_audio;
	Menu m_menu;
	Board m_board;
	DataDisplay m_dataDisplay;

	//Pages
	sf::RectangleShape m_helpMenu;
	sf::RectangleShape m_levelComplete;
	sf::RectangleShape m_congrats;

	//Game Data
	int m_currPage;
	int m_activePlayer;
	bool m_soundOn = true;

	//Other
	sf::Clock m_timer;
	std::vector <Audio> m_levelSounds;
	Audio m_clickAudio;
};