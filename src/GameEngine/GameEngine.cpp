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
    m_physicEngine.init(&m_resourceManager, 50, 20, 20, 9.81);
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

    ConvexShape * shape = m_resourceManager.getConvexShape();
    shape->setPointCount(4);
    shape->setFillColor(sf::Color::Blue);
    shape->setPosition(100, 100);
    shape->setLayer(9);
    shape->setPoint(0, sf::Vector2f(0, 0));
    shape->setPoint(1, sf::Vector2f(100, 0));
    shape->setPoint(2, sf::Vector2f(100, 100));
    shape->setPoint(3, sf::Vector2f(0, 100));

    ConvexShape * shape2 = m_resourceManager.getConvexShape();
    shape2->setPointCount(5);
    shape2->setFillColor(sf::Color::Black);
    shape2->setPosition(500, 400);
    shape2->setLayer(9);
    shape2->setPoint(0, sf::Vector2f(0, 0));
    shape2->setPoint(1, sf::Vector2f(100, 0));
    shape2->setPoint(2, sf::Vector2f(100, 100));
    shape2->setPoint(3, sf::Vector2f(0, 100));
    shape2->setPoint(4, sf::Vector2f(-50, 50));

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
    Player::Instance()->update(SECONDS_PER_UPDATE * TimeManager::TimeScale);
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
            if (event.key.code == 85)
            {
                m_graphicEngine.toggleWireframe();
                continue;
            }
            //if (event.key.code == 86)


        }
        m_eventConverter.processEvent(event, &m_controlMap);
    }
}