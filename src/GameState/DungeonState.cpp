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
    Player* m_player = Player::Instance();
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
                    if(m_player->getState() != m_player->LEFT)
                    {
                        std::cout << "start LEFT" << std::endl;
                        m_player->setState(Player::LEFT);
                        m_player->getRigidbody()->startMovingToLeft();
                    }
                }
                else
                {
                    std::cout << "stop LEFT" << std::endl;
                    m_player->setState(Player::IDLE);
                    m_player->getRigidbody()->stopMovingToLeft();
                }
            }
                break;
            case Actions::RIGHT:
            {
                if (event->isPressed())
                {
                    if(m_player->getState() != m_player->LEFT)
                    {
                        std::cout << "start LEFT" << std::endl;
                        m_player->setState(Player::LEFT);
                        m_player->getRigidbody()->startMovingToLeft();
                    }
                }
                else
                {
                    std::cout << "stop LEFT" << std::endl;
                    m_player->setState(Player::IDLE);
                    m_player->getRigidbody()->stopMovingToLeft();
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

    // Mouse hover actions
    m_player->getSprite()->setPosition(m_player->getRigidbody()->getPosition());
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
