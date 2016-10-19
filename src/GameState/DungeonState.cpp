#include "GameState/DungeonState.hpp"

/* explicit */ DungeonState::DungeonState()
: m_stateMachine(nullptr)
, m_resourceManager(nullptr)
, m_dungeon(nullptr)
{
    DungeonState::instance = nullptr;
}

void DungeonState::init(StateMachine  * stateMachine,
    ResourceManager * resourceManager)
{
    DungeonState::instance = this;

    m_physicEngine.init(resourceManager,3,3,3,9.80);
    rigid = m_physicEngine.getRigidBody();
    rigid->init(50,0,0,0,0,1.0f,0.0f,sf::Vector2f(0.0f,500.0f));
    Collider* c = m_physicEngine.getCollider();
    c->init((unsigned int)rigid->getPosition().x,(unsigned int) rigid->getPosition().y,64,64,
            64);
    m_physicEngine.bindRigidBodyAndCollider(rigid,c);
    c = m_physicEngine.getCollider();
    c->init(0,11*64,20*64,64,64);
    test = resourceManager->getSprite();
    test->setTexture(*resourceManager->getTexture("PLAYER"));
    test->setLayer(10);
    test->setPosition(rigid->getPosition());

    m_stateMachine = stateMachine;
    m_resourceManager = resourceManager;

    // Initializing the factory
    m_dungeonFactory.init(m_resourceManager);
}

/* virtual */ DungeonState::~DungeonState()
{
    DungeonState::instance = nullptr;
}

/* virtual */ void DungeonState::update(double dt)
{
    // TODO
    m_physicEngine.update(dt);
    test->setPosition(rigid->getPosition());
}

bool DungeonState::onEnter()
{
    // New dungeon for each onEnter()
    m_dungeon = m_dungeonFactory.generateDungeon();
    return true;
}

bool DungeonState::onExit()
{
    return true;
}