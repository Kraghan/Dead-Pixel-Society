#include <cstdlib>
#include "GameEngine/GameEngine.hpp"

int main()
{
    GameEngine gameEngine;

    gameEngine.init();
    gameEngine.start();

    return EXIT_SUCCESS;
}