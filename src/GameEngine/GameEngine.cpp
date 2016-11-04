#include "GameEngine/GameEngine.hpp"

GameEngine::GameEngine()
: m_isRunning(false)
, m_window(nullptr)
, m_graphicEngine()
, m_physicEngine()
, m_resourceLoader()
, m_resourceManager(&m_graphicEngine, &m_physicEngine)
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
                         "DPS", 1280, 768, 1500, 100, 100, 15, 2000);

    m_physicEngine.init(&m_resourceManager,50,20,20,9.80);

    // Getting the window
    m_window = m_graphicEngine.getWindow();

    // Activating wire-frame
    // Setting the framerate
    m_graphicEngine.wireframe(false);
    m_graphicEngine.setFramerate(60);
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
    /*Sprite * sprite = m_graphicEngine.getSprite();
    sprite->setLayer(5);
    sprite->setSmoothMotion(false);
    sprite->setTexture(*m_resourceManager.getTexture("PLAYER"));
    sprite->setPosition(50, 640);*/

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

            // sprite->move(300 * (float)(MS_PER_UPDATE / 1000), 0);
            // if(sprite->getPosition().x > 1100) sprite->setPosition(50, 640);
        }

        // Rendering
        m_graphicEngine.render(lag / MS_PER_UPDATE);
    }
}

void GameEngine::update()
{
    // Updating the game
    m_physicEngine.update(MS_PER_UPDATE * TimeManager::TimeScale);
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

        m_eventConverter.processEvent(event, &m_controlMap);
    }
}