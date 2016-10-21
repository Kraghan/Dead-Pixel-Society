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
    m_toLeft = false;
    m_toRight = false;
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
    if(m_toRight)
        m_velocity.x += m_acceleration;
    if(m_toLeft)
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

void RigidBody::stopMovementX() {
    m_velocity.x = 0.0f;
}

void RigidBody::stopMovementY() {
    m_velocity.y = 0.0f;
}

void RigidBody::startMovingToLeft() {
    m_toLeft = true;
}

void RigidBody::startMovingToRight() {
    m_toRight = true;
}

void RigidBody::stopMovingToLeft() {
    m_toLeft = false;
}

void RigidBody::stopMovingToRight() {
    m_toRight = false;
}

bool RigidBody::isMovingLeft() {
    return m_toLeft;
}

bool RigidBody::isMovingRight() {
    return m_toRight;
}

void RigidBody::goOnLeft(double dt) {
    m_velocity.x -= m_acceleration;
    if(m_velocity.x < -m_velocityMax)
        m_velocity.x = -m_velocityMax;

    move(getPosition().x+(m_velocity.y*(float)dt),getPosition().y);
}

void RigidBody::goOnRight(double dt) {
    m_velocity.x += m_acceleration;
    if(m_velocity.x > m_velocityMax)
        m_velocity.x = m_velocityMax;

    move(getPosition().x+m_velocity.y*(float)dt,getPosition().y);
}

