//
// Created by Kraghan on 17/10/2016.
//

#ifndef PROJECT_EVENTPROCESSED_HPP
#define PROJECT_EVENTPROCESSED_HPP


#include <GameEngine/Singleton.hpp>
#include "Interface/Event.hpp"
#include "EnumActions.hpp"

class EventProcessed : public Singleton<EventProcessed> {

public:
    static Actions action;
    static Event event;
    EventProcessed();
    void init();
};

#endif //PROJECT_EVENTPROCESSED_HPP
