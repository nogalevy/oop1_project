#include "Controller.h"


Controller::Controller()
    : m_window(sf::RenderWindow(sf::VideoMode(WINDOW_W, WINDOW_H), TITLE,  sf::Style::Close)),
    m_menu(),
    m_board(),
    m_dataDisplay(m_board.getCountdown()),
    m_currPage(MENU),
    m_activePlayer(KING),
    m_audio(Resources::instance().getMusic()),
    m_clickAudio(Resources::instance().getClickSoundEffect())
{
    setGameIcon();
    m_window.setFramerateLimit(60);
    setSound();
    initPages();
}

//-----------------------------------------------------------------

Controller::~Controller() {}

//-----------------------------------------------------------------

void Controller::startGame()
{
    m_audio.playMusic(DEFAULT_VOLUME ,true);

    while (m_window.isOpen())
    {
        sf::Vector2f location;
        m_window.clear();

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

void Controller::setGameIcon()
{
    sf::Image image = (*Resources::instance().getGameIcon());
    m_window.setIcon(image.getSize().x,image.getSize().y, image.getPixelsPtr());
}

//-----------------------------------------------------------------

void Controller::initPages()
{
    m_helpMenu = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_helpMenu.setTexture(Resources::instance().getHelpMenu());
    m_levelComplete = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_levelComplete.setTexture(Resources::instance().getLevelCompleted());
    m_congrats = sf::RectangleShape(sf::Vector2f(float(WINDOW_W), float(WINDOW_H)));
    m_congrats.setTexture(Resources::instance().getCongrats());
}

//-----------------------------------------------------------------

void Controller::handleNextLevel()
{
    m_levelSounds[END_LEVEL].playMusic(SOUND_EFFECTS_VOLUME);
    if (!m_board.setLevelNum())
    {
        m_board.resetLevelNum();
        m_activePlayer = KING;
        m_currPage = CONGRATS; 
    }
    m_board.loadLevel();
    resetCurrLevelData();
}

//-----------------------------------------------------------------

void Controller::handleBoardEvent(const sf::Event& event)
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

void Controller::handleMenuEvent(const sf::Event& event)
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

void Controller::handleHelpEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
        if (event.key.code == sf::Keyboard::Space)
        {
            m_currPage = MENU;
        }
}

//-----------------------------------------------------------------

void Controller::handleLevelComplete(const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
        if (event.key.code == sf::Keyboard::Space)
        {
            m_currPage = BOARD;
            m_dataDisplay.setCountdown(m_board.getCountdown());
        }
}

//-----------------------------------------------------------------

void Controller::handleCongrats(const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
        if (event.key.code == sf::Keyboard::Space)
        {
            m_currPage = MENU;
            m_audio.playMusic(DEFAULT_VOLUME, true);
        }
}

//-----------------------------------------------------------------

void Controller::handleKeyboardClick()
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

void Controller::playClickSound()
{
    m_clickAudio.playMusic(SOUND_EFFECTS_VOLUME);
}

//-----------------------------------------------------------------

void Controller::movePlayer(sf::Time& deltaTime)
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

void Controller::moveDwarfs(sf::Time &deltaTime)
{
    m_board.moveDwarfs(deltaTime);
}

//-----------------------------------------------------------------

void Controller::updateGameData()
{
    m_dataDisplay.setHasKey(m_board.getHasKey());
    if (m_board.getEndlevel())
    {
        handleNextLevel();
        if(m_currPage == BOARD)
            m_currPage = LEVELCOMPLETE;
    }

    applyBonus();
}

//-----------------------------------------------------------------

void Controller::applyBonus()
{

    BonusType bonus = m_board.getBonus();
    if (bonus != NONE)
    {
        switch (bonus)
        {
        case ADDTIME:
            m_dataDisplay.addTime(ADD_TIME_SEC);
            break;
        case SUBTIME:
            m_dataDisplay.addTime(SUB_TIME_SEC);
            break;
        case RMVDWARFS:
            m_board.removeDwarfs();
            break;
        case MOREDWARFS:
            m_board.moreDwarfs();
            break;
        case SLOWDWARFS:
            m_board.slowDwarfs();
            break;
        case FASTDWARFS:
            m_board.fastDwarfs();
            break;
        default:
            break;
        }
        m_board.setBonus(NONE);
    }
}

//-----------------------------------------------------------------

void Controller::checkLoseLevel()
{
    if (m_dataDisplay.isTimeEnd())
    {
        m_levelSounds[LOSE_LEVEL].playMusic(SOUND_EFFECTS_VOLUME);

        retryLevel();
    }
}

//-----------------------------------------------------------------

void Controller::retryLevel()
{
    m_board.createLevel();
    resetCurrLevelData();
    m_dataDisplay.setCountdown(m_board.getCountdown());
}

//-----------------------------------------------------------------

void Controller::setSound()
{
    for (size_t i = 0; i < NUM_OF_LEVEL_SOUND; i++)
    {
        m_levelSounds.push_back(Resources::instance().getLevelSoundEffect(Level_sound_effect_type(i)));
    }
}

//-----------------------------------------------------------------

void Controller::resetCurrLevelData()
{
    m_activePlayer = KING;
    m_dataDisplay.setHasKey(false);
    m_dataDisplay.setLevelNum(m_board.getLevelNum());
}

//-----------------------------------------------------------------

void Controller::drawCurrPage()
{
    switch (m_currPage)
    {
    case MENU:
        m_menu.draw(m_window);
        break;
    case BOARD:
        m_board.draw(m_window, m_activePlayer);
        checkLoseLevel();
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

void Controller::handleClick(const sf::Event& event)
{
     handleMenuClick(event);
}

//-----------------------------------------------------------------

void Controller::handleMenuClick(const sf::Event& event)
{
    int btn_num = m_menu.handleClick(event);
    switch (btn_num)
    {
    case START:
        playClickSound();
        m_currPage = BOARD;
        m_board.resetLevelNum();
        m_board.loadLevel();
        resetClock();
        resetCurrLevelData();
        m_dataDisplay.setCountdown(m_board.getCountdown());
        break;
    case HELP:
        playClickSound();
        m_currPage = HELPMENU;
        break;
    case EXIT:
        playClickSound();
        m_window.close();
        break;
    default:
        break;
    }
}

//-----------------------------------------------------------------

void Controller::handleBoardClick(const sf::Event& event)
{
    int btn_num = m_dataDisplay.handleClick(event);
    switch (btn_num)
    {
    case VOLUME:
        playClickSound();
        m_dataDisplay.updateVolumeIcon(!m_soundOn);
        if (m_soundOn)
            m_audio.stopPlayMusic();
        else
            m_audio.playMusic(DEFAULT_VOLUME, true);
        m_soundOn = !m_soundOn;
        break;
    case HOME:
    {
        playClickSound();
        m_currPage = MENU;
        m_board.resetLevelNum();
        break;
    }
    case RETRY:
    {
        playClickSound();
        retryLevel();
        break;
    }
    default:
        break;
    }
}

//-----------------------------------------------------------------

void Controller::handleHover(const sf::Vector2f location)
{
    m_menu.handleHover(location);
}

//-----------------------------------------------------------------

void Controller::resetClock()
{
    m_dataDisplay.resetClock();
}
