#include <WorldMap/WorldMap.hpp>
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


    WorldMap *m = new WorldMap(m_resourceManager);
    // TMP
    m_dungeonFactory.init(m_resourceManager);
    m_dungeon = m_dungeonFactory.generateDungeon();
    m_player.init(m_resourceManager);
    // TMP

    // m_stateMachine.pushState(m_worldMapState); ///< Soon
}

void Game::update(double dt)
{
    // Updating the game
    m_stateMachine.update(dt);
}
