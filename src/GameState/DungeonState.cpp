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
    Collider * floorCollider2 = resourceManager->getCollider();
    //Collider* floorCollider3 = resourceManager->getCollider();
    //Collider* floorCollider4 = resourceManager->getCollider();
    floorCollider->init(0,11,9,1,64);
    floorCollider2->init(12, 11, 10, 1, 64);
    //floorCollider3->init(9, 10, 3, 1, 64);
    //floorCollider4->init(12, 11, 10, 1, 64);

    Collider* leftCollider = resourceManager->getCollider();
    leftCollider->init(0,0,1,11,64);
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
                if (event->isPressed() && Player::Instance()->getState() !=
                                                  Player::LEFT)
                {
                    Player::Instance()->setState(Player::LEFT);
                }
                else if(!event->isPressed())
                {
                    Player::Instance()->setState(Player::IDLE);
                }
            }
                break;
            case Actions::RIGHT:
            {
                if (event->isPressed() && Player::Instance()->getState() !=
                                          Player::RIGHT)
                {
                    Player::Instance()->setState(Player::RIGHT);
                }
                else if(!event->isPressed())
                {
                    Player::Instance()->setState(Player::IDLE);
                }
            }
                break;
            case Actions::JUMP:
            {
                if (event->isPressed() && !Player::Instance()->isJumping())
                {
                    Player::Instance()->jump();
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

    // TMP
    // Buffering player
    Player * player = Player::Instance();

    // Buffering collider
    Collider * collider = player->getCollider();

    if(collider != nullptr)
    {
        if(collider->getPosition().x > 1270)
        {
            if(!m_dungeon->nextBlock())
            {
                std::cout << "The dungeon is over (end)!" << std::endl;
                m_stateMachine->popState();
            }

            player->getRigidbody()->move(0.0f, player->getRigidbody()->getPosition().y);
            collider->move(0.0f, collider->getPosition().y);
        }
        else if(collider->getPosition().x < -5)
        {
            if(!m_dungeon->previousBlock())
            {
                std::cout << "The dungeon is over (begin)!" << std::endl;
                m_stateMachine->popState();
            }

            player->getRigidbody()->move(1269.0f, player->getRigidbody()->getPosition().y);
            collider->move(1269.0f, collider->getPosition().y);
        }
    }
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
