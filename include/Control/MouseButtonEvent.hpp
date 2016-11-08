//
// Created by madjo on 05/11/2016.
//

#ifndef PROJECT_MOUSEBUTTON_HPP
#define PROJECT_MOUSEBUTTON_HPP


#include "MouseEvent.hpp"

class MouseButtonEvent : public MouseEvent
{
public :
    /**
     * \brief   Default constructor
     */
    MouseButtonEvent();

    /**
     * \brief   Constructor
     * @param action    Action of the event
     * @param pressed   Define if the key is pressed or released
     * @param position  Define the click position
     */
    MouseButtonEvent(Actions action, bool pressed, sf::Vector2i position);

    /**
     * \brief   Return true if the event is a mouse pressed
     */
    bool isPressed();

    /**
     * \brief   Set the type of the event
     */
    virtual void setEvent(Event event);
};


#endif //PROJECT_MOUSEBUTTON_HPP
