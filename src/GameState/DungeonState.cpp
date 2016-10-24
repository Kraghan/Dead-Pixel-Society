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

    unsigned int x = 6,y = 0;

    Collider* playerCollider = resourceManager->getCollider();
    playerCollider->init(x,y,1,1,64);

    playerRigidBody = resourceManager->getRigidBody();
    playerRigidBody->init(x,y,64,1.0f,10.0f,500.0f);
    playerRigidBody->startMovingToLeft();
    resourceManager->bindColliderToRigidBody(playerCollider,playerRigidBody);

    Collider* floorCollider = resourceManager->getCollider();
    floorCollider->init(0,11,20,1,64);
    /*Collider* leftWallCollider = resourceManager->getCollider();
    leftWallCollider->init(0,0,1,12,64);
    Collider* rightWallCollider = resourceManager->getCollider();
    rightWallCollider->init(20,11,1,12,64);*/

    test = resourceManager->getSprite();
    test->setTexture(*resourceManager->getTexture("PLAYER"));
    test->setLayer(10);
    test->setPosition(playerRigidBody->getPosition());

    m_stateMachine = stateMachine;
    m_resourceManager = resourceManager;

    // Initializing the factory
    m_dungeonFactory.init(m_resourceManager);


    // TMP
    ConvexShape * test = new ConvexShape();
    test = m_resourceManager->getConvexShape();
    test->setLayer(8);
    test->setWireColor(sf::Color::Red);

    test->setPosition(200, 200);
    test->setPointCount(5);
    test->setPoint(0, sf::Vector2f(0, 0));
    test->setPoint(1, sf::Vector2f(150, 10));
    test->setPoint(2, sf::Vector2f(120, 90));
    test->setPoint(3, sf::Vector2f(30, 100));
    test->setPoint(4, sf::Vector2f(0, 50));
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