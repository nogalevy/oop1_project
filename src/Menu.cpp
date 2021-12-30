#include "Menu.h"

Menu::Menu()
    : m_bgRect()
{
    m_bgTexture.loadFromFile("2.jpg");
    m_bgRect = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_bgRect.setTexture(&m_bgTexture);

    //------- create btns vector -----------
    //#fontexample
    //m_font.loadFromFile("font3.ttf");

    m_btns.resize(NUM_OF_MENU_BTNS); //TODO: change to const 
    setBtns();
}

void Menu::draw(sf::RenderWindow& window) const
{
    //int space = (WINDOW_W - BTN_W * NUM_OF_ICONS) / NUM_OF_ICONS; //space between obj buttons
    //draw background : window.draw(m_container);
    
    

    window.draw(m_bgRect);
    //draw btns
    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
    {
        window.draw(m_btns[i]);
    }
}

int Menu::handleClick(const sf::Event& event) const
{
    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
    {
        if (this->m_btns[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            return i;
    }
    return -1;
}

void Menu::handleHover(const sf::Vector2f& location, sf::RenderWindow& window)
{
    sf::Cursor cursor;

    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
    {
        if (this->m_btns[i].getGlobalBounds().contains(location))
        {
            m_btns[i].setFillColor(sf::Color::Color(55, 67, 87));
            if (cursor.loadFromSystem(sf::Cursor::Hand))
                window.setMouseCursor(cursor);
        }
        else
        {

            m_btns[i].setFillColor(sf::Color::Black);
            if (cursor.loadFromSystem(sf::Cursor::Arrow))
                window.setMouseCursor(cursor);
        }
    }
}


void Menu::setBtns()
{
    //text.setFont(m_font);
    //text.setString("Hello world");
    //text.setCharacterSize(44); // in pixels, not points!
    //text.setFillColor(sf::Color::Black);
    //text.setStyle(sf::Text::Bold);

    //calc center:
    std::vector<std::string> btn_text = { "Start", "Help", "Exit" };

    sf::Vector2f size = sf::Vector2f(200.f, 100.f);
    for (int i = 0; i < NUM_OF_MENU_BTNS; i++)
    {
        m_btns[i].setFont(*(Resources::instance().getFont()));
        m_btns[i].setString(btn_text[i]);
        m_btns[i].setCharacterSize(74); // in pixels, not points!
        m_btns[i].setFillColor(sf::Color::Black);
        m_btns[i].setStyle(sf::Text::Bold);
        m_btns[i].setPosition(sf::Vector2f(70, 100 * (i + 1)));


        //m_btns[i].setSize(size);
        //m_btns[i].setFillColor(sf::Color(sf::Color(122, 209, 226)));
        //m_btns[i].setPosition(sf::Vector2f(70, 200 * (i + 1) + 20));
    }
}
