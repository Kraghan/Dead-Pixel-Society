#include "GameEngine/Game.hpp"

/* explicit */ Game::Game()
: m_dungeon(nullptr)
, m_resourceManager(nullptr)
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

    // TMP
    m_dungeonFactory.init(m_resourceManager);

    // Creating a random dungeon
    m_dungeon = m_dungeonFactory.generateDungeon();

    // Creating the player
    m_player.init(m_resourceManager);
}

void Game::update(double dt)
{
    // Updating game
}
