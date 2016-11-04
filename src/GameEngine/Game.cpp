#include <Control/GameContext.hpp>
#include "GameEngine/Game.hpp"

/* explicit */ Game::Game()
{
    // None
}

/* virtual */ Game::~Game()
{
    // None
}

void Game::init(ResourceManager * resourceManager)
{
    // Getting resources
    m_resourceManager = resourceManager;

    // Initializing player
    Player::Instance()->init(resourceManager);

    // Initializing states
    PauseState::Instance()->init(&m_stateMachine, m_resourceManager);
    DungeonState::Instance()->init(&m_stateMachine, m_resourceManager);
    WorldMapState::Instance()->init(&m_stateMachine, m_resourceManager);

    // Pushing the first state =)
    m_stateMachine.pushState(WorldMapState::Instance());
}

void Game::update(double dt)
{
    // Updating the game
    m_stateMachine.update(dt);
}