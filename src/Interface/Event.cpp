//
// Created by Kraghan on 14/10/2016.
//

#include "Interface/Event.hpp"

Event::Event(sf::Vector2i position, EventType type, bool isPressed)
{
    m_position = position;
    m_pressed = isPressed;
    m_type = type;
}

EventType Event::getEventType()
{
    return m_type;
}

sf::Vector2i Event::getPosition()
{
    return m_position;
}

bool Event::isPressed()
{
    return m_pressed;
}