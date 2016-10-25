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
}

/* virtual */ WorldMapState::~WorldMapState()
{
    // None
}

/* virtual */ void WorldMapState::update(double dt)
{
    // TODO
}

bool WorldMapState::onEnter()
{
    // Pushing directly the next state
    // (Until we have the complete world map)
    m_stateMachine->pushState(DungeonState::Instance());

    return true;
}

bool WorldMapState::onExit()
{
    return true;
}
