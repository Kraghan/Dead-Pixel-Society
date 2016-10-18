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