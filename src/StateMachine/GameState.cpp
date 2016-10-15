#include "StateMachine/GameState.hpp"
#include "StateMachine/StateMachine.hpp"

/* explicit */ GameState::GameState(StateMachine * stateMachine)
: m_stateMachine(stateMachine)
{
    // None
}

/* virtual */ GameState::~GameState()
{
    // None
}