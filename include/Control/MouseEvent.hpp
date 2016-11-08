//
// Created by madjo on 05/11/2016.
//

#ifndef PROJECT_MOUSEEVENT_HPP
#define PROJECT_MOUSEEVENT_HPP


#include <SFML/System.hpp>
#include "Event.hpp"

class MouseEvent : public Event
{
private:
    /**
     * \brief   Position of the event
     */
    sf::Vector2i m_position;
public:

    /**
     * \brief   Default constructor
     */
    MouseEvent();

    /**
     * \brief   Constructor
     * @param type      Type of the event
     * @param action    Action of the event
     * @param active    Define if the event is entered/pressed or exited/released
     * @param position  Position of the event
     */
    MouseEvent(EventType type, Actions action, bool active, sf::Vector2i
    position);

    /**
     * \brief   Postion of the event getter
     */
    sf::Vector2i getPosition();

protected:
    /**
     * \brief   Position setter
     */
    void setPosition(sf::Vector2i position);
};


#endif //PROJECT_MOUSEEVENT_HPP
