//
// Created by Kraghan on 14/10/2016.
//

#ifndef PROJECT_EVENT_HPP
#define PROJECT_EVENT_HPP

#include <SFML/System.hpp>
#include "Interface/EventType.hpp"

class Event {
private:
    EventType m_type;
    sf::Vector2i m_position;
    bool m_pressed;
public:
    Event();
    Event(sf::Vector2i position, EventType type, bool isPressed);
    EventType getEventType();
    sf::Vector2i getPosition();
    bool isPressed();
};


#endif //PROJECT_EVENT_HPP
