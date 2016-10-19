//
// Created by madjo on 18/10/2016.
//

#include "PhysicEngine/RigidBody.hpp"

RigidBody::RigidBody()
: PhysicObjectBase()
{

}

void RigidBody::init(unsigned int x, unsigned int y, float mass,
                     float acceleration, float velocityMax)
{
    PhysicObjectBase::init(x,y,0,0,0);
    m_mass = mass;
    m_velocity = sf::Vector2f(0.0f,0.0f);
    m_acceleration = acceleration;
    m_velocityMax = velocityMax;
}

float RigidBody::getMass()
{
    return m_mass;
}

sf::Vector2f RigidBody::getVelocity()
{
    return m_velocity;
}

float RigidBody::getAcceleration()
{
    return m_acceleration;
}

void RigidBody::accelerate(float gravity)
{
    m_velocity.y += gravity*m_mass;
    m_velocity.x += m_acceleration;

    if(m_velocity.x < -m_velocityMax)
    {
        m_velocity.x = -m_velocityMax;
    }

    if(m_velocity.x > m_velocityMax)
    {
        m_velocity.x = m_velocityMax;
    }
}

void RigidBody::moveAuto(double dt)
{
    sf::Vector2f pos = getPosition();
    PhysicObjectBase::move((float)(pos.x+(m_velocity.x * dt)),(float)(pos.y+
            (m_velocity.y*dt)));
}

