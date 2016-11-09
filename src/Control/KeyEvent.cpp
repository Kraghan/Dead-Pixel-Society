//
// Created by madjo on 05/11/2016.
//

#include "Control/KeyEvent.hpp"

KeyEvent::KeyEvent()
:Event(EventType::KEY,Actions::NONE,false)
{
    // None
}

KeyEvent::KeyEvent(Actions action, bool pressed)
:Event(EventType::KEY,action,pressed)
{
    // None
}

bool KeyEvent::isPressed()
{
    return isActive();
}

void KeyEvent::setEvent(Event event)
{
    if(event.getEventType() == EventType::KEY)
    {
        KeyEvent* e = (KeyEvent*) &event;

        setAction(e->getAction());
        setActive(e->isActive());
        setEventType(EventType::KEY);
    }
}
