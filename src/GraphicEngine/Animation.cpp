#include "GraphicEngine/Animation.hpp"

/* explicit */ Animation::Animation()
{
    m_play = false;
    m_currentState = nullptr;
}

/* virtual */ Animation::~Animation()
{
    // None
}

void Animation::update(double dt)
{
    if(m_currentState != nullptr)
        m_currentState->update(dt);
}

void Animation::addState(std::string const&& key, AnimationState const&& state)
{
    // Added state
    m_stateList.emplace(key, state);
}

AnimationState * Animation::getState(const std::string& key)
{
    for(auto &it : m_stateList)
    {
        if(it.first == key)
            return &(it.second);
    }

    return nullptr;
}

void Animation::setState(std::string const& key)
{
    m_currentState = getState(key);

    if(m_currentState != nullptr)
        m_currentState->onEnter();
}

void Animation::start()
{
    m_play = true;
}

void Animation::pause()
{
    m_play = false;
}
