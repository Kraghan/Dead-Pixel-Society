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
    m_physicEngine.init(&m_resourceManager, 500, 200, 200, 9.81);
    // m_soundEngine.init();

    // Initializing the graphic engine
    m_graphicEngine.init(&m_resourceManager,
                         "DPS", 1280, 768, 1500, 100, 100, 15, 2000);

    // Getting the window
    m_window = m_graphicEngine.getWindow();

    // Activating wire-frame
    // Setting the framerate
    m_graphicEngine.wireframe(false);
    m_graphicEngine.setFramerate(60.0);
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
    sf::Clock clock;
    double lag = 0.0;
    double previous = clock.getElapsedTime().asSeconds();

    while(m_isRunning)
    {
        double current = clock.getElapsedTime().asSeconds();
        double elapsed = current - previous;
        previous = current;

        lag += elapsed;

        // Processing inputs
        processInput();

        while(lag >= SECONDS_PER_UPDATE)
        {
            // Updating
            update();

            // Retrieve elapsed time
            lag -= SECONDS_PER_UPDATE;
        }

        // Rendering
        m_graphicEngine.render(lag / SECONDS_PER_UPDATE);
    }
}

void GameEngine::update()
{
    // Updating the game
    m_physicEngine.update(SECONDS_PER_UPDATE * TimeManager::TimeScale);
    m_game.update(SECONDS_PER_UPDATE * TimeManager::TimeScale);
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
        if(event.type == sf::Event::KeyReleased)
        {
            switch((int)event.key.code)
            {
                case 26 : m_graphicEngine.toggleWireframe(0); continue;
                case 27 : m_graphicEngine.toggleWireframe(1); continue;
                case 28 : m_graphicEngine.toggleWireframe(2); continue;
                case 29 : m_graphicEngine.toggleWireframe(3); continue;
                case 30 : m_graphicEngine.toggleWireframe(4); continue;
                case 31 : m_graphicEngine.toggleWireframe(5); continue;
                case 32 : m_graphicEngine.toggleWireframe(6); continue;
                case 33 : m_graphicEngine.toggleWireframe(7); continue;
                case 34 : m_graphicEngine.toggleWireframe(8); continue;
                case 35 : m_graphicEngine.toggleWireframe(9); continue;
                case 53 : DrawPhysics::toggleDrawPhysics(); continue;
                default: break;
            }
        }
        m_eventConverter.processEvent(event, &m_controlMap);
    }
}