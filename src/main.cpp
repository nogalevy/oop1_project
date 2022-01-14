#include <stdlib.h>
#include <iostream>
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <vector>


int main()
{
    auto my_controller = Controller();
    my_controller.startGame();

    return EXIT_SUCCESS;
}
/*

int main()
{
	
    auto my_window = window();
	my_window.run();
    

    //------ fullscreen option ---------------
    // App.create(sf::VideoMode(800, 600, 32), "SFML Controller", sf::Style::Fullscreen);
   
    //----- create window ----------------
    auto window = sf::RenderWindow(window_sizee, "AHHHHHHHHHHHHHHHHHHHH" , sf::Style::Titlebar | sf::Style::Fullscreen | sf::Style::Close) );

    //----- create background image ---------
    auto bg = sf::Texture();
    bg.loadFromFile("2.jpg");
    auto bg_rect = sf::RectangleShape(bg_sizee);
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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
        }
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
*/