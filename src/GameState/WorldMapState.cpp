#include "GameState/WorldMapState.hpp"

/* explicit */ WorldMapState::WorldMapState()
: m_stateMachine(nullptr)
, m_resourceManager(nullptr)
{
    // None
}

void WorldMapState::init(StateMachine  * stateMachine,
    ResourceManager * resourceManager)
{
    m_stateMachine = stateMachine;
    m_resourceManager = resourceManager;
    m_worldMap.init(m_resourceManager);
}

/* virtual */ WorldMapState::~WorldMapState()
{
    m_worldMap.~WorldMap();
}

/* virtual */ void WorldMapState::update(double dt)
{
    m_worldMap.update();
}

bool WorldMapState::onEnter()
{
    // Pushing directly the next state
    // (Until we have the complete world map)
    //m_stateMachine->pushState(DungeonState::Instance());

    return true;
}

bool WorldMapState::onExit()
{
    return true;
}
