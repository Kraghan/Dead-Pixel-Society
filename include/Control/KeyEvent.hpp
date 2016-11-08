//
// Created by madjo on 05/11/2016.
//

#ifndef PROJECT_KEYEVENT_HPP
#define PROJECT_KEYEVENT_HPP


#include "Event.hpp"

class KeyEvent : public Event
{
public:
    /**
     * \brief   Default constructor
     */
    KeyEvent();

    /**
     * \brief   Constructor
     * @param action    Action of the event
     * @param pressed   Define if the key is pressed or released
     */
    KeyEvent(Actions action, bool pressed);

    /**
     * \brief   Return true if the event is a key pressed
     */
    bool isPressed();
};

#endif //PROJECT_KEYEVENT_HPP
