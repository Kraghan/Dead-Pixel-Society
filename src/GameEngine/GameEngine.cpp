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
    double lag = 0.0;
    double previous = Clock::getCurrentTime();

    m_isRunning = true;
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
            lag -= MS_PER_UPDATE;
        }

        printf("LAG = %lf\n", lag);
        printf("CUR = %lf\n", current);
        printf("PRE = %lf\n", previous);
        printf("ELP = %lf\n", elapsed);

        // TODO : render(lag / MS_PER_UPDATE);
    }

}


