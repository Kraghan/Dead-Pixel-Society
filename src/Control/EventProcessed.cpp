//
// Created by Kraghan on 17/10/2016.
//

#include "Control/EventProcessed.hpp"
Actions EventProcessed::action = Actions::NONE;
Event EventProcessed::event = Event();

EventProcessed::EventProcessed()
{

}

void EventProcessed::init()
{
    EventProcessed::action = Actions::NONE;
    EventProcessed::event = Event();
}