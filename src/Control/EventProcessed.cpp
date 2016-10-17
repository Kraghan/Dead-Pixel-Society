//
// Created by Kraghan on 17/10/2016.
//

#include "Control/EventProcessed.hpp"

EventProcessed::EventProcessed()
{
    m_action = nullptr;
    m_event = nullptr;
}

EventProcessed::EventProcessed(Actions* actions, Event* event)
{
    m_action = actions;
    m_event = event;
}

Actions* EventProcessed::getAction()
{
    return m_action;
}

Event* EventProcessed::getEvent()
{
    return m_event;
}