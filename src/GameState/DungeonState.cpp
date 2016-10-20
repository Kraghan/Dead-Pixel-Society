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

    Collider* playerCollider = resourceManager->getCollider();
    playerCollider->init(0,0,1,1,64);

    playerRigidBody = resourceManager->getRigidBody();
    playerRigidBody->init(5,1,64,1.0f,0.0f,500.0f);
    resourceManager->bindColliderToRigidBody(playerCollider,playerRigidBody);

    Collider* floorCollider = resourceManager->getCollider();
    floorCollider->init(0,10,20,11,64);

    test = resourceManager->getSprite();
    test->setTexture(*resourceManager->getTexture("PLAYER"));
    test->setLayer(10);
    test->setPosition(playerRigidBody->getPosition());

/*  m_physicEngine.init(resourceManager,3,3,3,9.80);
    rigid = m_physicEngine.getRigidBody();
    rigid->init(0,0,64,1.0f,0.0f,500.0f);
    Collider* c = m_physicEngine.getCollider();
    c->init((unsigned int)rigid->getPosition().x,(unsigned int)
                    rigid->getPosition().y,1,1,64);
    m_physicEngine.bindRigidBodyAndCollider(rigid,c);
    c = m_physicEngine.getCollider();
    c->init(0,11,20,1,64);
    std::cout<< c->getDimension().x << " " << c->getDimension().y <<std::endl;

*/
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
    m_resourceManager->getPhysicEngine()->update(dt);
    test->setPosition(playerRigidBody->getPosition());
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