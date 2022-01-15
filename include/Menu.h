#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Resources.h"
#include "view_constants.h"
#include "utilities.h"

const int NUM_OF_MENU_BTNS = 3; //Tali: you want to leave these here?
const std::string BTN_TEXT[NUM_OF_MENU_BTNS] = { "Start", "Help", "Exit" };

class Menu 
{
public:
    Menu();
    ~Menu() = default;

    void draw(sf::RenderWindow& window) const;
    int handleClick(const sf::Event& event) const;
    void handleHover(const sf::Vector2f& location, sf::RenderWindow& window);

private:
    void setBtns();

    sf::RectangleShape m_bgRect;
    sf::Texture m_bgTexture;
    std::vector<sf::Text> m_btns;
};