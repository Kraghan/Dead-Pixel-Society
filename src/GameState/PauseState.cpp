#include "GameState/PauseState.hpp"

/* explicit */ PauseState::PauseState()
: m_stateMachine(nullptr)
, m_resourceManager(nullptr)
{
    // None
}

void PauseState::init(StateMachine  * stateMachine,
    ResourceManager * resourceManager)
{
    m_stateMachine = stateMachine;
    m_resourceManager = resourceManager;
}

/* virtual */ PauseState::~PauseState()
{
    // None
}

/* virtual */ void PauseState::update(double dt)
{
    // TODO
}

bool PauseState::onEnter()
{
    // TODO
    return true;
}

bool PauseState::onExit()
{
    // TODO
    return true;
}