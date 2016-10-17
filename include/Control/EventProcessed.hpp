//
// Created by Kraghan on 17/10/2016.
//

#ifndef PROJECT_EVENTPROCESSED_HPP
#define PROJECT_EVENTPROCESSED_HPP


#include "Interface/Event.hpp"
#include "EnumActions.hpp"

class EventProcessed {
private:
    Actions* m_action;
    Event* m_event;

public:
    EventProcessed();
    EventProcessed(Actions* actions, Event* event);
    Actions* getAction();
    Event* getEvent();
};


#endif //PROJECT_EVENTPROCESSED_HPP
