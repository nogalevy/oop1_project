#include <stdlib.h>
#include <iostream>
#include "window.h"
#include <SFML/Graphics.hpp>
#include <vector>

sf::VideoMode window_size = sf::VideoMode(1280, 870);
sf::Vector2f bg_size = sf::Vector2f(1280.f, 870.f);

void drawBtns(sf::RenderWindow &window, std::vector<sf::RectangleShape> btns)
{
    //calc center:
    sf::Vector2f size = sf::Vector2f(200.f, 100.f);
    for (int i = 0; i < 3; i++)
    {
        btns[i].setSize(size);
        btns[i].setFillColor(sf::Color(sf::Color(122, 209, 226)));
        btns[i].setPosition(sf::Vector2f(70, 200 * (i + 1) + 20));

        window.draw(btns[i]);
    }
}

int main()
{
	/* 
    auto my_window = window();
	my_window.run();
    */

    //------ fullscreen option ---------------
    // App.create(sf::VideoMode(800, 600, 32), "SFML Window", sf::Style::Fullscreen);
   
    //----- create window ----------------
    auto window = sf::RenderWindow(window_size, "AHHHHHHHHHHHHHHHHHHHH" /*, sf::Style::Titlebar | sf::Style::Fullscreen | sf::Style::Close) */);

    //----- create background image ---------
    auto bg = sf::Texture();
    bg.loadFromFile("2.jpg");
    auto bg_rect = sf::RectangleShape(bg_size);
    bg_rect.setTexture(&bg);
   
    //------- create btns vector -----------
    std::vector<sf::RectangleShape> btns(3);

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        //sf::Event event;
        sf::Vector2f location;

        window.clear(sf::Color(sf::Color(14,45,32)));

        window.draw(bg_rect);
        drawBtns(window, btns);
        //window.draw();
        window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            window.close();
        }
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            window.close();
        }*/
        if (auto event = sf::Event{}; window.pollEvent(event)  )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
                // Add more cases to handle other events
            default:
                break;
            }
        }
    }

	return EXIT_SUCCESS;
}