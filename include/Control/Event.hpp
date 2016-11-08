//
// Created by madjo on 05/11/2016.
//

#ifndef PROJECT_EVENT_HPP
#define PROJECT_EVENT_HPP


#include <Control/EnumActions.hpp>
#include "EventType.hpp"

class Event
{
private :
    /**
     * \brief   Define the type of the event
     */
    EventType m_type;

    /**
     * \brief   Define the action of the event
     */
    Actions m_actions;

    /**
     * \brief   Define if the event is entered/pressed or exited/released
     */
    bool m_active;
public :

    /**
     * Default constructor
     */
    Event();

    /**
     * \brief   Constructor
     * @param type      Type of the event
     * @param action    Action of the event
     * @param active    Define if the event is entered/pressed or exited/released
     */
    Event(EventType type,Actions action,bool active);

    /**
     * \brief   Type of the event getter
     */
    EventType getEventType();

    /**
     * \brief   Action of the event getter
     */
    Actions getAction();

    /**
     * \brief   Set the type of the event
     */
    //virtual void setEvent(Event event) = 0;

protected:
    /**
     * \brief   Define if the event is entered/pressed or exited/released
     */
    bool isActive();

    /**
     * \brief   Action setter
     */
    void setAction(Actions action);

    /**
     * \brief   EventType setter
     */
    void setEventType(EventType type);

    /**
     * \brief   Active setter
     */
    void setActive(bool active);
};


#endif //PROJECT_EVENT_HPP
