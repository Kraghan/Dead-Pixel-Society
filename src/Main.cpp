#include <cstdlib>
#include "GameEngine/GameEngine.hpp"

int main(void)
{
    GameEngine gameEngine;

    gameEngine.init();
    gameEngine.start();

    return EXIT_SUCCESS;
}