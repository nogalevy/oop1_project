#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Resources.h"
#include "view_constants.h"
#include "utilities.h"


class Menu 
{
public:
    Menu();
    ~Menu() = default;

    //Draw Functions
    void draw(sf::RenderWindow& window) const;
    void drawBtns(sf::RenderWindow& window) const;

    //Events Functions
    int handleClick(const sf::Event& event) const;
    void handleHover(const sf::Vector2f& location);

private:
    //Set Functions
    void setBtns();
    void setBackground();

    //======Members==========

    sf::RectangleShape m_bgRect;
    sf::Texture m_bgTexture;
    std::vector<sf::Text> m_btns;
};