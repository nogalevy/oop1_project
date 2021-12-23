#include "Menu.h"

Menu::Menu()
    : m_bgRect()
{
    short size = 3;
    m_bgTexture.loadFromFile("2.jpg");
    m_bgRect = sf::RectangleShape(sf::Vector2f(1280.f, 870.f));
    m_bgRect.setTexture(&m_bgTexture);

    //------- create btns vector -----------
    m_btns.resize(size); //TODO: change to const 
    setBtns();
}

void Menu::draw(sf::RenderWindow& window) const
{
    //int space = (WINDOW_W - BTN_W * NUM_OF_ICONS) / NUM_OF_ICONS; //space between obj buttons
    //draw background : window.draw(m_container);
    
    window.draw(m_bgRect);
    //draw btns
    for (int i = 0; i < 3; i++)
    {
        window.draw(m_btns[i]);
    }
}


void Menu::setBtns()
{
    //calc center:
    sf::Vector2f size = sf::Vector2f(200.f, 100.f);
    for (int i = 0; i < 3; i++)
    {
        m_btns[i].setSize(size);
        m_btns[i].setFillColor(sf::Color(sf::Color(122, 209, 226)));
        m_btns[i].setPosition(sf::Vector2f(70, 200 * (i + 1) + 20));
    }
}
