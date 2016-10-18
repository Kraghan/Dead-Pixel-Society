#include "GameState/PauseState.hpp"

/* explicit */ PauseState::PauseState()
: m_stateMachine(nullptr)
, m_resourceManager(nullptr)
{
    PauseState::instance = nullptr;
}

void PauseState::init(StateMachine  * stateMachine,
    ResourceManager * resourceManager)
{
    PauseState::instance = this;

    m_stateMachine = stateMachine;
    m_resourceManager = resourceManager;
}

/* virtual */ PauseState::~PauseState()
{
    PauseState::instance = nullptr;
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