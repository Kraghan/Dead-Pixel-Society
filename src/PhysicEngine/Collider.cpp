//
// Created by Kraghan on 12/10/2016.
//

#include "PhysicEngine/Collider.hpp"

Collider::Collider(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int size)
{
    m_position = sf::Vector2u(x,y);

    m_dimension = sf::Vector2u(width,height);

    m_size = size;
}

void Collider::debug()
{
    using namespace std;
    cout<< "Collider : position (" << m_position.x <<","<< m_position.y << ")" << "dimension (" << m_dimension.x*m_size << "," << m_dimension.y*m_size << ")" <<endl;
}