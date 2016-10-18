//
// Created by madjo on 18/10/2016.
//

#include "PhysicEngine/RigidBody.hpp"

RigidBody::RigidBody()
: PhysicObjectBase()
{

}

void RigidBody::init(unsigned int x, unsigned int y, unsigned int width,
                     unsigned int height, unsigned int size, float mass,
                     float acceleration, sf::Vector2f velocityMax)
{
    PhysicObjectBase::init(x,y,width,height,size);
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
    m_velocity.y -= gravity*m_mass;
    m_velocity.x += m_acceleration;

    if(m_velocity.y < -m_velocityMax.y)
    {
        m_velocity.y = -m_velocityMax.y;
    }

    if(m_velocity.y > -m_velocityMax.y)
    {
        m_velocity.y = m_velocityMax.y;
    }

    if(m_velocity.x < -m_velocityMax.x)
    {
        m_velocity.x = -m_velocityMax.x;
    }

    if(m_velocity.x > -m_velocityMax.x)
    {
        m_velocity.x = m_velocityMax.x;
    }
}

void RigidBody::move()
{
    sf::Vector2i pos = getPosition();
    PhysicObjectBase::move((int)(pos.x+m_velocity.x),(int)(pos.y+m_velocity.y));
}

