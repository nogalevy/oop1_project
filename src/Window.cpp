#include "Window.h"

sf::VideoMode window_size = sf::VideoMode(1280, 870);

Window::Window()
    : m_window(sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H), TITLE)),
    m_menu(),
    m_board(),
    m_dataDisplay(),
    m_bgTexture(),
    m_image(),
    m_currPage(MENU),
    m_activePlayer(KING),
    m_audio(Resources::instance().getMusic())
{
    m_window.setFramerateLimit(60);
    m_helpMenu = sf::RectangleShape(sf::Vector2f(float(WINDOW_W/2), float(WINDOW_H/2)));
    m_helpMenu.setTexture(Resources::instance().getHelpMenu());
    m_helpMenu.setPosition(sf::Vector2f(float(WINDOW_W / 4), float(WINDOW_H / 4)));
}

//-----------------------------------------------------------------

Window::~Window()
{
}

//-----------------------------------------------------------------

void Window::startGame()
{
    m_audio.playMusic(true);

   // if(m_board.isTimer())
        //settimer

    while (m_window.isOpen())
    {
        sf::Vector2f location;
    
        m_window.clear(sf::Color(sf::Color(26, 26 ,26)));

        drawCurrPage();

        //m_window.draw(m_helpMenu);

        m_window.display();

        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (m_currPage == BOARD)
                handleBoardEvent(event);
            else
                handleMenuEvent(event);
        }

        handleKeyboardClick();
    }
}

//-----------------------------------------------------------------

void Window::handleNextLevel()
{
    if (!m_board.setLevelNum())
    {
        m_currPage = MENU; //we need to update here that the user finished all levels
    }
    //m_timer.restart();
    m_activePlayer = KING;
    m_dataDisplay.resetClock();
    m_dataDisplay.setHasKey(false);
    m_dataDisplay.setLevelNum(m_board.getLevelNum());
    m_board.loadNextLevel();
}

void Window::handleBoardEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        if (event.key.code == sf::Keyboard::P)
        {
            m_activePlayer = (m_activePlayer + 1) % 4;
            std::cout << "active player : " <<  m_activePlayer << std::endl;
        }
        //break;
        else if (event.key.code == sf::Keyboard::Space)
        {
            if (!m_board.setLevelNum())
            {
                m_currPage = MENU; //we need to update here that the user finished all levels
            }
            m_board.loadNextLevel();
        }
        break;
    }
    case sf::Event::MouseButtonReleased:
        handleBoardClick(event);
        break;
    default:
        break;
    }
}

//-----------------------------------------------------------------

void Window::handleMenuEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        handleMenuClick(event);
        break;
    case sf::Event::MouseMoved:
    {
        sf::Vector2f location = m_window.mapPixelToCoords(
            { event.mouseMove.x, event.mouseMove.y });
        if (m_currPage == MENU)
            handleHover(location);
        break;
    }
    default:
        break;
    }
}

//-----------------------------------------------------------------

void Window::handleKeyboardClick()
{
    sf::Time deltaTime = m_timer.restart();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_window.close();
    if (m_currPage == BOARD)
    {
        movePlayer(deltaTime);
        moveDwarfs(deltaTime);
        updateGameData();
    }
}

//-----------------------------------------------------------------

void Window::movePlayer(sf::Time deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_board.move(sf::Vector2f(-1, 0), deltaTime, m_activePlayer);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_board.move(sf::Vector2f(1, 0), deltaTime, m_activePlayer);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_board.move(sf::Vector2f(0, -1), deltaTime, m_activePlayer);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_board.move(sf::Vector2f(0, 1), deltaTime, m_activePlayer);
    }
  
}

//-----------------------------------------------------------------

void Window::moveDwarfs(sf::Time deltaTime)
{
    m_board.moveDwarfs(deltaTime);
}

//-----------------------------------------------------------------

void Window::updateGameData()
{
    m_dataDisplay.setHasKey(m_board.getHasKey());
    if (m_board.getEndlevel())
    {
        handleNextLevel();
    }
}

//-----------------------------------------------------------------

void Window::drawCurrPage()
{
    switch (m_currPage)
    {
    case MENU:
        m_menu.draw(m_window);
        break;
    case BOARD:
        //bool key;
        //std::cout << "board page\n";
        m_board.draw(m_window);

        //key = m_board.getHasKey(); //Noga : not sure (?)

        m_dataDisplay.draw(m_window, m_activePlayer);
        break;
    default:
        break;
    }
}

//-----------------------------------------------------------------

void Window::handleClick(const sf::Event& event)
{

        handleMenuClick(event);

}

//-----------------------------------------------------------------

void Window::handleMenuClick(const sf::Event& event)
{
    int btn_num = m_menu.handleClick(event);
    switch (btn_num)
    {
    case START:
        //openGamePage();
        m_currPage = BOARD;
        m_dataDisplay.resetClock();
        break;
    case HELP:
    {   
        //m_window.draw(m_helpMenu);
        break;
    }
    case EXIT:
        m_window.close();
        break;
    default:
        break;
    }
}

void Window::handleBoardClick(const sf::Event& event)
{
    int btn_num = m_dataDisplay.handleClick(event);
    switch (btn_num)
    {
    case VOLUME:
        //openGamePage();
        m_dataDisplay.updateVolumeIcon(!m_soundOn);
        if (m_soundOn)
            m_audio.stopPlayMusic();
        else
            m_audio.playMusic();
        m_soundOn = !m_soundOn;
        break;
    case HOME:
    {
        //m_window.draw(m_helpMenu);
        break;
    }
    default:
        break;
    }
}

//-----------------------------------------------------------------

void Window::handleHover(const sf::Vector2f location)
{
    m_menu.handleHover(location, m_window);
}

//-----------------------------------------------------------------

void Window::resetClock()
{
    m_dataDisplay.resetClock();
}






