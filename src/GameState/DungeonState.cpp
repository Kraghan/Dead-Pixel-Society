#include <GameEngine/TimeManager.hpp>
#include <Control/EventProcessed.hpp>
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

    TimeManager::TimeScale = 1.0f;
}

/* virtual */ DungeonState::~DungeonState()
{
    // None
}

/* virtual */ void DungeonState::update(double dt)
{
    Player* m_player = Player::Instance();
    m_player->getSprite()->setPosition(m_player->getRigidbody()->getPosition());
    switch (EventProcessed::action)
    {
        case Actions::LEFT :
            if(m_player->getState() != m_player->LEFT)
            {
                m_player->setState(m_player->LEFT);
                m_player->getRigidbody()->stopMovingToRight();
                m_player->getRigidbody()->startMovingToLeft();
            }
            break;
        case Actions::RIGHT :
            if(m_player->getState() != m_player->RIGHT)
            {
                m_player->setState(m_player->RIGHT);
                m_player->getRigidbody()->stopMovingToLeft();
                m_player->getRigidbody()->startMovingToRight();
            }
            break;
        case Actions::JUMP :
            if(m_player->getState() != m_player->JUMP)
            {
                m_player->setState(m_player->JUMP);
                m_player->getRigidbody()->addForce(sf::Vector2f(0.0f, -500.0f));
            }
            break;
        default:
            m_player->setState(m_player->IDLE);
            m_player->getRigidbody()->stopMovementX();
            break;
    }

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
