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

    // Init game context
    GameContext::instance = new GameContext();


    // Initializing states
    m_pauseState.init(&m_stateMachine, m_resourceManager);
    m_dungeonState.init(&m_stateMachine, m_resourceManager);
    m_worldMapState.init(&m_stateMachine, m_resourceManager);

    // Pushing the first state =)
    m_stateMachine.pushState(&m_worldMapState);
}

void Game::update(double dt)
{
    // Updating the game
    m_stateMachine.update(dt);
}