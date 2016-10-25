#include <GameEngine/TimeManager.hpp>
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
    playerRigidBody->startMovingToRight();
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

    test->setSmoothMotion(true);
    test->setRigidBody(playerRigidBody);

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