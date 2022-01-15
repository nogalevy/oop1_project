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