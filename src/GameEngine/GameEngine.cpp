#include "GameEngine/GameEngine.hpp"

GameEngine::GameEngine()
: m_isRunning(false)
, m_graphicEngine()
, m_resourceManager(&m_graphicEngine)
, m_window(nullptr)
{
    // TODO
}

/* virtual */ GameEngine::~GameEngine()
{
    // TODO
}

void GameEngine::init()
{
    // Initializing other engine
    // Window name
    // Window size
    // Sprites count
    // Texts count
    // Layer count
    // Layer size
    m_graphicEngine.init("DPS", 1280, 720, 500, 100, 10, 500);

    // Getting the window
    m_window = m_graphicEngine.getWindow();
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

        // Processing inputs
        processInput();

        while(lag >= MS_PER_UPDATE)
        {
            // Updating
            // TODO : update();

            // Rendering
            m_graphicEngine.render();

            // Retrieve elapsed time
            lag -= MS_PER_UPDATE;
        }
    }
}

void GameEngine::processInput()
{
    // Creating the receiver event object
    sf::Event event;

    // Event loop
    while(m_window->pollEvent(event))
    {
        // The user wants to exit the game
        if (event.type == sf::Event::Closed)
        {
            m_isRunning = false;
        }
    }
}