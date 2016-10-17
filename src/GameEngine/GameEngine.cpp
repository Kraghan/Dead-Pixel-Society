#include "GameEngine/GameEngine.hpp"

GameEngine::GameEngine()
: m_isRunning(false)
, m_window(nullptr)
, m_graphicEngine()
, m_resourceLoader()
, m_resourceManager(&m_graphicEngine)
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
    // Loading and getting resources
    m_resourceLoader.init();
    m_resourceLoader.load(&m_resourceManager);

    // Initializing other engine
    // m_physicEngine.init();
    // m_soundEngine.init();

    // Initializing the graphic engine
    m_graphicEngine.init(&m_resourceManager,
                         "DPS", 1280, 768, 500000, 100, 15, 2500);

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
    // TMP
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
    // TMP


    // Activating wire-frame
    // Setting the framerate
    m_graphicEngine.wireframe(true);
    m_graphicEngine.setFramerate(500.0);

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

            // Retrieve elapsed time
            lag -= MS_PER_UPDATE;
        }

        // Rendering
        m_graphicEngine.render();
    }
}

void GameEngine::processInput()
{
    // Creating the receiver event object
    sf::Event event;

    // Event loop
    while(m_window->pollEvent(event))
    {
        bool isPressed = false;
        Actions action = Actions::NONE;
        GameContext* context = GameContext::getContext();
        sf::Vector2i position = sf::Vector2i(-1,-1);
        EventType type = EventType::VOID;

        // The user wants to exit the game
        if (event.type == sf::Event::Closed)
        {
            m_isRunning = false;
        }

        // The player use a controller
        if(context->isContextController())
        {
            // A controller button is pressed
            if (event.type == sf::Event::JoystickButtonPressed)
            {
                isPressed = true;
                action = m_controlMap.getAction((int) event.joystickButton.button);
            }
            // A controller button is released
            else if (event.type == sf::Event::JoystickButtonReleased)
            {
                action = m_controlMap.getAction((int) event.joystickButton.button);
            }
        }
        // The player use a keyboard and a mouse
        else
        {
            // A key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                isPressed = true;
                action = m_controlMap.getAction((int) event.key.code);
            }
            // A key is released
            else if (event.type == sf::Event::KeyReleased)
            {
                action = m_controlMap.getAction((int) event.key.code);
            }
            // A mouse button is pressed
            else if (event.type == sf::Event::MouseButtonPressed)
            {

                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    position = sf::Vector2i(event.mouseButton.x,event.mouseButton.y);
                    action = m_controlMap.getAction(-1);
                    if(action == Actions::VALIDATE)
                    {
                        type = EventType::MOUSE_LEFT_CLICK;
                    }
                }
                else if(event.mouseButton.button == sf::Mouse::Right)
                {
                    position = sf::Vector2i(event.mouseButton.x,event.mouseButton.y);
                    action = m_controlMap.getAction(-2);
                    if(action == Actions::VALIDATE)
                    {
                        type = EventType::MOUSE_LEFT_CLICK;
                    }
                }
                else if(event.mouseButton.button == sf::Mouse::Middle)
                {
                    position = sf::Vector2i(event.mouseButton.x,event.mouseButton.y);
                    action = m_controlMap.getAction(-3);
                    if(action == Actions::VALIDATE)
                    {
                        type = EventType::MOUSE_LEFT_CLICK;
                    }
                }

            }
            // A mouse button is released
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    action = m_controlMap.getAction(-1);

                }
                else if(event.mouseButton.button == sf::Mouse::Right)
                {
                    action = m_controlMap.getAction(-2);

                }
                else if(event.mouseButton.button == sf::Mouse::Middle)
                {
                    action = m_controlMap.getAction(-3);

                }
            }
            // Used for hover detection for buttons
            else if (event.type == sf::Event::MouseMoved) {
                type = EventType::MOUSE_HOVER;
                position = sf::Vector2i(event.mouseMove.x,event.mouseMove.y);
            }

            // std::cout<< "Action : " << action <<std::endl;

            Event e = Event(position,type,isPressed);

            // TODO : Give the action to the physicEngine
            // TODO : Spread the new event e in the interface
        }

    }
}