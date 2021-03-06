#include "Menu.h"

Menu::Menu()
    : m_bgRect()
{
    setBackground();
    setBtns();
}

//-----------------------------------------------------------------

void Menu::draw(sf::RenderWindow& window) const
{
    window.draw(m_bgRect);
    drawBtns(window);
}

//-----------------------------------------------------------------

void Menu::drawBtns(sf::RenderWindow& window) const
{
    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
        window.draw(m_btns[i]);
}

//-----------------------------------------------------------------

int Menu::handleClick(const sf::Event& event) const
{
    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
    {
        if (this->m_btns[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            return i;
    }
    return MINUS_ONE;
}

//-----------------------------------------------------------------

void Menu::handleHover(const sf::Vector2f& location)
{
    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
    {
        if (this->m_btns[i].getGlobalBounds().contains(location))
        {
            m_btns[i].setFillColor(HOVER_MENU_BTN_COLOR);
        }
        else
        {
            m_btns[i].setFillColor(WHITE_COLOR);
        }
    }
}

//-----------------------------------------------------------------

void Menu::setBtns()
{
    m_btns.resize(NUM_OF_MENU_BTNS);

    sf::Vector2f size = sf::Vector2f(200.f, 100.f);
    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
    {
        m_btns[i].setFont(*(Resources::instance().getFont()));
        m_btns[i].setString(BTN_TEXT[i]);
        m_btns[i].setCharacterSize(MENU_FONT_SIZE);
        m_btns[i].setFillColor(WHITE_COLOR);
        m_btns[i].setStyle(sf::Text::Bold);
        m_btns[i].setPosition(sf::Vector2f((400 * i + 210), (WINDOW_H - 190)));
    }
}

//-----------------------------------------------------------------

void Menu::setBackground()
{
    m_bgRect = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_bgRect.setTexture(Resources::instance().getMenuBackground());
}
