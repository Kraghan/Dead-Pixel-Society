#include "GameEngine/GameEngine.hpp"

GameEngine::GameEngine()
: m_isRunning(false)
, m_window(nullptr)
, m_graphicEngine()
, m_resourceLoader()
, m_resourceManager(&m_graphicEngine)
, m_game()
, m_controlMap()
, m_eventConverter()
{
    // TODO
}

/* virtual */ GameEngine::~GameEngine()
{
    // TODO
}

void GameEngine::init()
{
    // Loading and getting resources
    m_resourceLoader.init();
    m_resourceLoader.load(&m_resourceManager);

    // Initializing other engine
    // m_physicEngine.init();
    // m_soundEngine.init();

    // Initializing the graphic engine
    m_graphicEngine.init(&m_resourceManager,
                         "DPS", 1280, 768, 2000, 100, 15, 2000);

    // Getting the window
    m_window = m_graphicEngine.getWindow();

    // Activating wire-frame
    // Setting the framerate
    m_graphicEngine.wireframe(true);
    m_graphicEngine.setFramerate(120.0);
}

void GameEngine::start()
{
    // The game is already running
    if(m_isRunning) return;

    // Launching internal class game
    m_game.init(&m_resourceManager);

    // Setting game loop attribute
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
            update();

            // Retrieve elapsed time
            lag -= MS_PER_UPDATE;
        }

        // Rendering
        m_graphicEngine.render();
    }
}

void GameEngine::update()
{
    // Updating the game
    m_game.update(MS_PER_UPDATE * TimeManager::TimeScale);
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

        EventProcessed e = m_eventConverter.processEvent(event, &m_controlMap);
    }
}
