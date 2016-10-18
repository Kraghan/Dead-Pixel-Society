#include "GameState/WorldMapState.hpp"

/* explicit */ WorldMapState::WorldMapState()
: m_stateMachine(nullptr)
, m_resourceManager(nullptr)
{
    WorldMapState::instance = nullptr;
}

void WorldMapState::init(StateMachine  * stateMachine,
    ResourceManager * resourceManager)
{
    WorldMapState::instance = this;

    m_stateMachine = stateMachine;
    m_resourceManager = resourceManager;
}

/* virtual */ WorldMapState::~WorldMapState()
{
    WorldMapState::instance = nullptr;
}

/* virtual */ void WorldMapState::update(double dt)
{
    // TODO
}

bool WorldMapState::onEnter()
{
    // Pushing directly the next state
    // (Until we have the complete world map)
    m_stateMachine->pushState(DungeonState::instance);

    return true;
}

bool WorldMapState::onExit()
{
    return true;
}
