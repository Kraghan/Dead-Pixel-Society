#include "GameState/DungeonState.hpp"

/* explicit */ DungeonState::DungeonState()
: m_stateMachine(nullptr)
, m_resourceManager(nullptr)
, m_dungeon(nullptr)
, m_theme(nullptr)
{
    // None
}

void DungeonState::init(StateMachine  * stateMachine,
    ResourceManager * resourceManager)
{

    Collider* floorCollider = resourceManager->getCollider();
    floorCollider->init(0,11,20,1,64);

    Collider* leftCollider = resourceManager->getCollider();
    leftCollider->init(0,0,1,20,64);
    Collider* rightCollider = resourceManager->getCollider();
    rightCollider->init(19,0,1,11,64);

    m_stateMachine = stateMachine;
    m_resourceManager = resourceManager;

    // Initializing the factory
    m_dungeonFactory.init(m_resourceManager);

    setDungeonTheme(m_resourceManager->getDungeonTheme("FOREST"));
}

/* virtual */ DungeonState::~DungeonState()
{
    // None
}

/* virtual */ void DungeonState::update(double dt)
{
    // Key actions
    if(EventProcessed::event.getEventType() == EventType::KEY)
    {
        KeyEvent* event = (KeyEvent*) &EventProcessed::event;
        switch (event->getAction())
        {
            case Actions::LEFT:
            {
                if (event->isPressed())
                {
                    Player::Instance()->setState(Player::LEFT);
                }
                else
                {
                    Player::Instance()->setState(Player::IDLE);
                }
            }
                break;
            case Actions::RIGHT:
            {
                if (event->isPressed())
                {
                    Player::Instance()->setState(Player::RIGHT);
                }
                else
                {
                    Player::Instance()->setState(Player::IDLE);
                }
            }
                break;
            case Actions::JUMP:
            {
                if (event->isPressed())
                {

                }
            }
                break;
            default:
            {

            }
                break;
        }
    }
    // Mouse button actions
    EventProcessed::Instance()->init();
}

bool DungeonState::onEnter()
{
    // New dungeon for each onEnter()
    if(m_theme == nullptr) m_dungeon = m_dungeonFactory.generateDungeon();
    else m_dungeon = m_dungeonFactory.generateDungeon(m_theme);

    return true;
}

bool DungeonState::onExit()
{
    return true;
}

void DungeonState::setDungeonTheme(DungeonTheme * theme)
{
    m_theme = theme;
}
