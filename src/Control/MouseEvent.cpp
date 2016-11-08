//
// Created by madjo on 05/11/2016.
//

#include "Control/MouseEvent.hpp"

MouseEvent::MouseEvent()
{
    // None
}

MouseEvent::MouseEvent(EventType type, Actions action, bool active,
                       sf::Vector2i position)
: Event(type,action,active)
{
    m_position = position;
}

sf::Vector2i MouseEvent::getPosition()
{
    return m_position;
}

void MouseEvent::setPosition(sf::Vector2i position)
{
    m_position = position;
}
