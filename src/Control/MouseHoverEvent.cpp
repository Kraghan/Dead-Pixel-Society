//
// Created by madjo on 05/11/2016.
//

#include "Control/MouseHoverEvent.hpp"

MouseHoverEvent::MouseHoverEvent()
:MouseEvent(EventType::MOUSE_HOVER,Actions::NONE,false,sf::Vector2i())
{
    // None
}

MouseHoverEvent::MouseHoverEvent(Actions action, bool entered, sf::Vector2i
position)
:MouseEvent(EventType::MOUSE_HOVER,action,entered,position)
{
    // None
}

bool MouseHoverEvent::isEntered()
{
    return isActive();
}

void MouseHoverEvent::setEvent(Event event)
{
    if(event.getEventType() == EventType::MOUSE_HOVER)
    {
        MouseHoverEvent* e = (MouseHoverEvent*) &event;
        setAction(e->getAction());
        setActive(e->isActive());
        setEventType(EventType::MOUSE_HOVER);
        setPosition(e->getPosition());
    }

}
