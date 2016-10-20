//
// Created by madjo on 18/10/2016.
//

#include "PhysicEngine/RigidBody.hpp"

RigidBody::RigidBody()
: PhysicObjectBase()
{

}

void RigidBody::init(unsigned int x, unsigned int y, unsigned int size, float
mass,
                     float acceleration, float velocityMax)
{
    PhysicObjectBase::init(x,y,0,0,size);
    m_mass = mass;
    m_velocity = sf::Vector2f(0.0f,0.0f);
    m_acceleration = acceleration;
    m_velocityMax = velocityMax;
    toLeft = false;
    toRight = false;
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

void RigidBody::applyGravity(double dt, float gravity)
{
    m_velocity.y += gravity*m_mass;

    sf::Vector2f pos = getPosition();
    move(pos.x,pos.y+m_velocity.y*(float)dt);
}

void RigidBody::accelerate()
{
    if(toRight)
        m_velocity.x += m_acceleration;
    if(toLeft)
        m_velocity.x -= m_acceleration;

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

void RigidBody::stopMovementX() {
    m_velocity.x = 0.0f;
}

void RigidBody::stopMovementY() {
    m_velocity.y = 0.0f;
}

void RigidBody::startMovingToLeft() {
    toLeft = true;
}

void RigidBody::startMovingToRight() {
    toRight = true;
}

void RigidBody::stopMovingToLeft() {
    toLeft = false;
}

void RigidBody::stopMovingToRight() {
    toRight = false;
}

