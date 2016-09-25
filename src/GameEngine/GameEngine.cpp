#include "GameEngine/GameEngine.hpp"

GameEngine::GameEngine() : m_isRunning(false)
{
    // TODO
}

/* virtual */ GameEngine::~GameEngine()
{
    // TODO
}

void GameEngine::init()
{
    // TODO
}

void GameEngine::start()
{
    if(m_isRunning) return;

    m_isRunning = true;
    gameLoop();
}

void GameEngine::gameLoop()
{
    double lag = 0.0;
    double previous = Clock::getCurrentTime();

    while(m_isRunning)
    {
        double current = Clock::getCurrentTime();
        double elapsed = current - previous;
        previous = current;

        lag += elapsed;

        // TODO : processInput();

        while(lag >= MS_PER_UPDATE)
        {
            // TODO : update();
            // TODO : render(lag / MS_PER_UPDATE);
            lag -= MS_PER_UPDATE;
        }
    }
}


