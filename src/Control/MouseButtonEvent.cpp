//
// Created by madjo on 05/11/2016.
//

#include "Control/MouseButtonEvent.hpp"

MouseButtonEvent::MouseButtonEvent()
:MouseEvent(EventType::MOUSE_BUTTON,Actions::NONE,false,sf::Vector2i())
{
    // None
}

MouseButtonEvent::MouseButtonEvent(Actions action, bool pressed,sf::Vector2i
position)
:MouseEvent(EventType::MOUSE_BUTTON,action,pressed,position)
{
    // None
}

bool MouseButtonEvent::isPressed()
{
    return isActive();
}

void MouseButtonEvent::setEvent(Event event)
{
    if(event.getEventType() == EventType::MOUSE_BUTTON)
    {
        MouseButtonEvent* e = (MouseButtonEvent*) &event;

        setAction(e->getAction());
        setActive(e->isActive());
        setEventType(EventType::MOUSE_BUTTON);
        setPosition(e->getPosition());
    }
}
