//
// Created by madjo on 05/11/2016.
//

#include "Control/Event.hpp"

Event::Event()
{
    m_type = EventType::EVENT_TYPE_NULL;
    m_actions = Actions::NONE;
    m_active = false;
}

Event::Event(EventType type, Actions action, bool active)
{
    m_type = type;
    m_actions = action;
    m_active = active;
}

EventType Event::getEventType()
{
    return m_type;
}

Actions Event::getAction()
{
    return m_actions;
}

bool Event::isActive()
{
    return m_active;
}

void Event::setActive(bool active)
{
    m_active = active;
}

void Event::setEventType(EventType type)
{
    m_type = type;
}

void Event::setAction(Actions action)
{
    m_actions = action;
}
