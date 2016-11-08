//
// Created by Kraghan on 17/10/2016.
//

#ifndef PROJECT_EVENTPROCESSED_HPP
#define PROJECT_EVENTPROCESSED_HPP


#include <GameEngine/Singleton.hpp>
#include "EnumActions.hpp"
#include "Event.hpp"

class EventProcessed : public Singleton<EventProcessed> {

public:
    static Event event;
    EventProcessed();
    void init();
};

#endif //PROJECT_EVENTPROCESSED_HPP
