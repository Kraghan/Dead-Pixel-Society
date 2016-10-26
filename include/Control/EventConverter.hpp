//
// Created by Kraghan on 17/10/2016.
//

#ifndef PROJECT_EVENTCONVERTER_HPP
#define PROJECT_EVENTCONVERTER_HPP


#include <Interface/Event.hpp>
#include <SFML/Window/Event.hpp>
#include "EnumActions.hpp"
#include "GameContext.hpp"
#include "ControlMap.hpp"
#include "EventProcessed.hpp"

class EventConverter {
public:
    EventConverter();
    void processEvent(const sf::Event event,const ControlMap* controlMap);
};


#endif //PROJECT_EVENTCONVERTER_HPP
