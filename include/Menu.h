#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Resources.h"

//#include "utilities.h"
#include "view_constants.h"

//sf::Vector2f bg_size = sf::Vector2f(1280.f, 870.f);
const int NUM_OF_MENU_BTNS = 3;
class Menu 
{
public:
    Menu();
    void draw(sf::RenderWindow& window) const;
    int handleClick(const sf::Event& event) const;
    void handleHover(const sf::Vector2f& location, sf::RenderWindow& window);

private:
    sf::RectangleShape m_bgRect;
    sf::Texture m_bgTexture;
    //std::vector<sf::RectangleShape> m_btns;
    std::vector<sf::Text> m_btns;

    void setBtns();
};