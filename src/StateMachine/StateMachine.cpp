#include "StateMachine/StateMachine.hpp"

/* explicit */ StateMachine::StateMachine()
{
    // None
}

/* virtual */ StateMachine::~StateMachine()
{
    // None
}

/* virtual */ void StateMachine::update(double dt)
{
    // Updating only the last state
    if(!m_gameStates.empty()) m_gameStates.back()->update(dt);
}

void StateMachine::pushState(GameState * pState)
{
    // Pushing the state at the top of
    // State machine, calling onEnter()
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void StateMachine::changeChange(GameState * pState)
{
    popState();
    pushState(pState);
}

void StateMachine::popState()
{
    // If the state machine isn't empty
    if(!m_gameStates.empty())
    {
        // If onExit succeed
        if(m_gameStates.back()->onExit())
        {
            // Removing the last state
            m_gameStates.pop_back();
        }
    }
}