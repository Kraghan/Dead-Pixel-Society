//
// Created by Kraghan on 17/10/2016.
//

#include "Control/EventProcessed.hpp"
Event EventProcessed::event = Event();

EventProcessed::EventProcessed()
{

}

void EventProcessed::init()
{
    EventProcessed::event = Event();
}