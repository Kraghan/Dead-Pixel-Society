#include "GameEngine/Game.hpp"

/* explicit */ Game::Game()
: m_resourceManager(nullptr)
{
    // None
}

/* virtual */ Game::~Game()
{
    // None
}

void Game::init(ResourceManager * resourceManager)
{
    m_resourceManager = resourceManager;
}

void Game::update(double dt)
{
    // Updating game
}
