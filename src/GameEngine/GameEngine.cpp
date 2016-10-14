#include "GameEngine/GameEngine.hpp"

GameEngine::GameEngine()
: m_isRunning(false)
, m_graphicEngine()
, m_resourceManager(&m_graphicEngine)
, m_window(nullptr)
, m_controlMap()
{
    // TODO
}

/* virtual */ GameEngine::~GameEngine()
{
    // TODO
}

void GameEngine::init()
{

    m_resourceManager.loadTexture("../res/Texture/DebugPanel.png", "DEBUG_PANEL");
    m_resourceManager.loadFont("../res/Font/Roboto-Light.ttf", "DEBUG_FONT");


    // Initializing other engine
    // The resource manager
    // Window name
    // Window size
    // Sprites count
    // Texts count
    // Layer count
    // Layer size
    m_graphicEngine.init(&m_resourceManager,
                         "DPS", 1280, 768, 2000, 100, 15, 2500);

    // Getting the window
    m_window = m_graphicEngine.getWindow();
}

void GameEngine::start()
{
    m_controlMap.debug();
    if(m_isRunning) return;

    m_isRunning = true;
    gameLoop();
}

void GameEngine::gameLoop()
{
    double lag = 0.0;
    double previous = Clock::getCurrentTime();

    m_resourceManager.loadTexture("../res/Texture/TileTest.png", "FOREST");

    BlockParser parser;
    BlockComponent blockComponent = parser.readFile(
            "../res/Dungeon/RoomBlock/block_1.map");

    BlockAttributes const& blockAttributes = blockComponent.getBlockAttribute();

    Dungeon dungeon(&m_resourceManager);

    std::vector < BlockAttributes * > blocks;
    blocks.push_back((BlockAttributes * )&blockAttributes);
    blocks.push_back((BlockAttributes * )&blockAttributes);
    blocks.push_back((BlockAttributes * )&blockAttributes);
    blocks.push_back((BlockAttributes * )&blockAttributes);

    dungeon.init(blocks, "FOREST");

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
        else if (event.type == sf::Event::KeyPressed)
        {
            std::cout<< event.key.code << std::endl;
        }
        else if (event.type == sf::Event::JoystickButtonPressed)
        {
            std::cout<< event.joystickButton.button << std::endl;
        }
    }
}