#include "Window.h"

sf::VideoMode window_size = sf::VideoMode(1280, 870);

Window::Window()
    : m_window(sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H), TITLE)),
    m_menu(),
    m_board(),
    m_dataDisplay(m_board.getCountdown()),
    m_bgTexture(),
    m_image(),
    m_currPage(MENU),
    m_activePlayer(KING),
    m_audio(Resources::instance().getMusic())
{
    m_window.setFramerateLimit(60);
    m_helpMenu = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_helpMenu.setTexture(Resources::instance().getHelpMenu());
    setSound();

    if (m_board.isCountdown())
    {
        std::cout << "board has counter" << std::endl;
        m_dataDisplay.setCountdown(m_board.getCountdown());
    }

    m_levelComplete = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_levelComplete.setTexture(Resources::instance().getLevelCompleted());
   // m_levelComplete.setPosition(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));

    m_congrats = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_congrats.setTexture(Resources::instance().getCongrats());
}

//-----------------------------------------------------------------

Window::~Window()
{
}

//-----------------------------------------------------------------

void Window::startGame()
{
    m_audio.playMusic(DEFAULT_VOLUME ,true);

    while (m_window.isOpen())
    {
        sf::Vector2f location;
        m_window.clear(sf::Color(sf::Color(26, 26 ,26)));

        drawCurrPage();
        m_window.display();

        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (m_currPage == BOARD)
                handleBoardEvent(event);
            else if (m_currPage == MENU)
                handleMenuEvent(event);
            else if (m_currPage == HELPMENU)
                handleHelpEvent(event);
            else if (m_currPage == LEVELCOMPLETE)
                handleLevelComplete(event);
            else
                handleCongrats(event);
        }

        handleKeyboardClick();
    }
}

//-----------------------------------------------------------------

void Window::handleNextLevel()
{
    m_levelSounds[END_LEVEL].playMusic(15);
    if (!m_board.setLevelNum())
    {
        m_board.resetLevelNum();
        m_activePlayer = KING;
        m_currPage = CONGRATS; //we need to update here that the user finished all levels

    }
    m_board.loadLevel();
    resetCurrLevelData();
}

//-----------------------------------------------------------------

void Window::handleBoardEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        if (event.key.code == sf::Keyboard::P)
        {
            m_activePlayer = (m_activePlayer + 1) % 4;
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

void Window::handleHelpEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
        if (event.key.code == sf::Keyboard::Space)
        {
            m_currPage = MENU;
        }
}

//-----------------------------------------------------------------

void Window::handleLevelComplete(const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
        if (event.key.code == sf::Keyboard::Space)
        {
            m_currPage = BOARD;
            m_dataDisplay.setCountdown(m_board.getCountdown());
        }
}

//-----------------------------------------------------------------

void Window::handleCongrats(const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
        if (event.key.code == sf::Keyboard::Space)
        {
            m_currPage = MENU;
        }
}

//-----------------------------------------------------------------

void Window::handleKeyboardClick()
{
    sf::Time deltaTime = m_timer.restart();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        m_window.close();
    }
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
        if(m_currPage == BOARD)
            m_currPage = LEVELCOMPLETE;
    }
    BonusType bonus = m_board.getBonus();
    if (bonus != NONE)
    {
        switch (bonus)
        {
        case ADDTIME:
            std::cout << "ADD TIME BONUS\n";
            m_dataDisplay.addTime(10, m_window);

            //add 10 seconds?
            break;
        case SUBTIME:
            std::cout << "SUB TIME BONUS\n";

            m_dataDisplay.addTime(-10, m_window);

            //remove 10 seconds?
            break;
        case RMVDWARFS:
            std::cout << "RMV DWARFS BONUS\n";

            m_board.removeDwarfs();
            break;
        case MOREDWARFS:
            std::cout << "MORE DWARFS BONUS\n";

            m_board.moreDwarfs();
            break;
        case SLOWDWARFS:
            std::cout << "SLOW DWARFS BONUS\n";

            m_board.slowDwarfs();
            break;
        case FASTDWARFS:
            std::cout << "FAST DWARFS BONUS\n";

            m_board.fastDwarfs();
            break;
        default:
            break;
        }
        m_board.setBonus(NONE);
    }
}

//-----------------------------------------------------------------

void Window::checkLoseLevel()
{
    if (m_dataDisplay.isTimeEnd())
    {
        m_levelSounds[LOSE_LEVEL].playMusic(10);

        m_board.createLevel();
        resetCurrLevelData();
        m_dataDisplay.setCountdown(m_board.getCountdown());

    }
}

void Window::setSound()
{
    for (size_t i = 0; i < NUM_OF_LEVEL_SOUND; i++)
    {
        m_levelSounds.push_back(Resources::instance().getLevelSoundEffect(Level_sound_effect_type(i)));

    }
}

void Window::resetCurrLevelData()
{
    m_activePlayer = KING;
    m_dataDisplay.setHasKey(false);
    m_dataDisplay.setLevelNum(m_board.getLevelNum());
    //m_board.loadLevel();
    //resetClock();
    //m_dataDisplay.setCountdown(m_board.getCountdown());
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

        m_board.draw(m_window, m_activePlayer);
        checkLoseLevel();

        //key = m_board.getHasKey(); //Noga : not sure (?)

        m_dataDisplay.draw(m_window, m_activePlayer);
        break;
    case HELPMENU:
        m_window.draw(m_helpMenu);
        break;
    case LEVELCOMPLETE:
        m_window.draw(m_levelComplete);
        break;
    case CONGRATS:
        m_window.draw(m_congrats);
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
        m_board.resetLevelNum();
        m_board.loadLevel();
        resetClock();

        m_dataDisplay.setCountdown(m_board.getCountdown());
        resetCurrLevelData();
        break;
    case HELP:
        m_currPage = HELPMENU;
        break;
    case EXIT:
        m_window.close();
        break;
    default:
        break;
    }
}

//-----------------------------------------------------------------

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
            m_audio.playMusic(DEFAULT_VOLUME, true);
        m_soundOn = !m_soundOn;
        break;
    case HOME:
    {
        //move this to function ? we have the same 3 lines in 'handleNextLevel'
        m_currPage = MENU;
        m_activePlayer = KING;
        //m_board.;
        m_board.resetLevelNum();
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
