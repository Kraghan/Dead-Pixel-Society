#include <iostream>
#include "GraphicEngine/AnimationState.hpp"

/* explicit */ AnimationState::AnimationState()
{
    m_elapsed = 0.0;
}

void AnimationState::onEnter()
{
    m_elapsed = 0.0;
    m_currentStep = 0;
}

void AnimationState::update(double dt)
{
    m_elapsed += dt;

    if(m_elapsed >= m_delay)
    {
        m_elapsed = 0;

        if(m_currentStep == m_step)
        {
            if(m_repeat)
            {
                m_currentStep = 0;
            }
        }

        m_sprite->setTextureRect(sf::IntRect(
                m_position.x + m_currentStep * m_offset,
                m_position.y,
                m_size.x,
                m_size.y));

        m_currentStep++;
    }
}

void AnimationState::init(Sprite * pSrite, bool repeat, sf::Vector2i pos,
sf::Vector2i size, int offset, char step, double delay)
{
    m_sprite = pSrite;

    m_repeat = repeat;
    m_size = size;
    m_position = pos;

    m_step = step;
    m_offset = offset;

    m_delay = delay;
    m_currentStep = 0;
}

void AnimationState::setRepeat(bool repeat)
{
    m_repeat = repeat;
}
