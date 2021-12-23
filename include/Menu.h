#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "view_constants.h"

//sf::Vector2f bg_size = sf::Vector2f(1280.f, 870.f);

class Menu {
public:
    Menu();
    void draw(sf::RenderWindow& window) const;
    void handleClick() const;
    void handleHover() const;

private:
    sf::RectangleShape m_bgRect;
    sf::Texture m_bgTexture;
    std::vector<sf::RectangleShape> m_btns;

    void setBtns();
};