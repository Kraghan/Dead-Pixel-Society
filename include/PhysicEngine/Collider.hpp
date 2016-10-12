//
// Created by madjo on 12/10/2016.
//

#ifndef PROJECT_COLLIDER_HPP
#define PROJECT_COLLIDER_HPP


#include <iostream>
#include <SFML/System.hpp>

class Collider {
private:
    sf::Vector2u m_position, m_dimension;
    unsigned int m_size;
public:
    Collider(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int size);

    void debug();
};


#endif //PROJECT_COLLIDER_HPP
