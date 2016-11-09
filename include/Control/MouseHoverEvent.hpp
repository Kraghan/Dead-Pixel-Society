//
// Created by madjo on 05/11/2016.
//

#ifndef PROJECT_MOUSEHOVER_HPP
#define PROJECT_MOUSEHOVER_HPP


#include <Control/EnumActions.hpp>
#include "MouseEvent.hpp"

class MouseHoverEvent : public MouseEvent
{
public:
    /**
     * \brief   Default constructor
     */
    MouseHoverEvent();

    /**
     * \brief   Constructor
     * @param action    Action of the event
     * @param pressed   Define if the key is pressed or released
     * @param position  Define cursor position
     */
    MouseHoverEvent(Actions action, bool entered, sf::Vector2i position);

    /**
     * \brief   Return true if the event is the cursor entered
     */
    bool isEntered();

    /**
     * \brief   Set the type of the event
     */
    void setEvent(Event event);
};


#endif //PROJECT_MOUSEHOVER_HPP
