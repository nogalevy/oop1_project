#include "Window.h"

sf::VideoMode window_size = sf::VideoMode(1280, 870);

Window::Window()
    : m_window(sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H), TITLE)),
    m_menu(),
    m_board(),
    m_bgTexture(),
    m_image(),
    m_currPage(MENU),
    m_activePlayer(0/*KING*/)
{
    //#fontexample
    //m_font.loadFromFile("font2.ttf");
    m_window.setFramerateLimit(60);
}

Window::~Window()
{
}

void Window::startGame()
{
    /*
        Noga: 
        Two options to display pages:
            1. Like the 'LodeRunner' game - one main loop that first send us to other loop in
                'startScreen' class and display the first page (menu), and when click on start game 
                send exit from that loop and return to the main loop in our 'window'
            2. while loop in window that decide to draw page by some enum - 
                the enum will update for exxample by clicking the 'start game' button (thats good if we want 
                to give access to the menu while playing the game) 

    
    */

    while (m_window.isOpen())
    {
        //#fontexample
        //sf::Text text;
        //// select the font
        //text.setFont(m_font); // font is a sf::Font
        //// set the string to display
        //text.setString("Hello world");
        //// set the character size
        //text.setCharacterSize(44); // in pixels, not points!
        //// set the color
        //text.setFillColor(sf::Color::Black);
        //// set the text style
        //text.setStyle(sf::Text::Bold);

        //sf::Event event;
        sf::Vector2f location;

        m_window.clear(sf::Color(sf::Color(14, 45, 32)));

        //TODO: move to draw function
        drawCurrPage();
        

        //#fontexample
        //m_window.draw(text);
        // 
       // m_window.draw(bg_rect);
        //window.draw();
        m_window.display();

        if (m_currPage == BOARD)
        {
            isKeyPressed();
        }

        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
                // Add more cases to handle other events
            case sf::Event::MouseButtonReleased:		// stopping and resuming background music
                handleClick(event);
                break;
            default:
                break;
            }
        }
    }
}

void Window::drawCurrPage()
{
    switch (m_currPage)
    {
    case MENU:
        m_menu.draw(m_window);
        break;
    case BOARD:
        m_board.draw(m_window);
        break;
    default:
        break;
    }
}

void Window::handleClick(const sf::Event& event)
{
    if (1 /*m_currPage == MENU */ )
    {
        handleMenuClick(event);
    }
}


void Window::isKeyPressed()
{
    sf::Time deltaTime = m_timer.restart();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_board.move(sf::Vector2f(-1, 0), deltaTime, m_activePlayer);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_board.move(sf::Vector2f(1, 0), deltaTime, m_activePlayer);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_board.move(sf::Vector2f(0, -1), deltaTime, m_activePlayer);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_board.move(sf::Vector2f(0, 1), deltaTime, m_activePlayer);
    }
}

void Window::handleMenuClick(const sf::Event& event)
{
    int btn_num = m_menu.handleClick(event);
    switch (btn_num)
    {
    case START:
        //openGamePage();
        m_currPage = BOARD;
        break;
    case HELP:
        //m_menu.openHelpWindow();
        break;
    case EXIT:
        m_window.close();
        break;
    default:
        break;
    }
}
