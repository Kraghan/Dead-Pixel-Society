//
// Created by Kraghan on 18/10/2016.
//

#include <iostream>
#include "PhysicEngine/RigidBody.hpp"

void RigidBody::release(RigidBody* &rigidBody)
{
    rigidBody->setFree();
    rigidBody = nullptr;
}

RigidBody::RigidBody()
: PhysicObjectBase()
{
    m_isFalling = false;
    m_toLeft = false;
    m_toRight = false;
}

void RigidBody::init(unsigned int x, unsigned int y, unsigned int size, float
mass, float acceleration, float velocityMax)
{
    PhysicObjectBase::init(x,y,0,0,size);
    m_mass = mass;
    m_velocity = sf::Vector2f(0.0f,0.0f);
    m_acceleration = acceleration;
    m_velocityMax = velocityMax;
    m_toLeft = false;
    m_toRight = false;
    m_isFalling = false;
}

float RigidBody::getMass()
{
    return m_mass;
}

bool RigidBody::isFalling()
{
    return m_isFalling;
}

void RigidBody::setFalling(bool falling)
{
    m_isFalling = falling;
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
    m_velocity.y += gravity*dt;

    sf::Vector2f pos = getPosition();
    move(pos.x,pos.y+m_velocity.y);
}

void RigidBody::stopMovementX()
{
    m_velocity.x = 0.0f;
}

void RigidBody::stopMovementY()
{
    m_velocity.y = 0.0f;
}

void RigidBody::startMovingToLeft()
{
    m_toLeft = true;
}

void RigidBody::startMovingToRight()
{
    m_toRight = true;
}

void RigidBody::stopMovingToLeft()
{
    m_toLeft = false;
}

void RigidBody::stopMovingToRight()
{
    m_toRight = false;
}

bool RigidBody::isMovingLeft()
{
    return m_toLeft;
}

bool RigidBody::isMovingRight()
{
    return m_toRight;
}

void RigidBody::goOnLeft(double dt)
{
    //if(collidingDown)
    //{
        m_velocity.x -= m_acceleration * dt;
        if (m_velocity.x < -m_velocityMax)
            m_velocity.x = -m_velocityMax;
    /*}
    else
    {
        m_velocity.x += 2*m_acceleration*dt;
        if(m_velocity.x > 0)
            m_velocity.x = 0;
    }*/
    move(getPosition().x+(m_velocity.x),getPosition().y);
}

void RigidBody::goOnRight(double dt)
{
    //if(collidingDown)
    //{
        m_velocity.x += m_acceleration*dt;
        if(m_velocity.x > m_velocityMax)
            m_velocity.x = m_velocityMax;
    /*}
    else
    {
        m_velocity.x -= 2*m_acceleration*dt;
        if(m_velocity.x < 0)
            m_velocity.x = 0;
    }*/
    move(getPosition().x+m_velocity.x,getPosition().y);
}

void RigidBody::addForce(sf::Vector2f force)
{
    m_velocity += force;
}

void RigidBody::slowDown(double dt)
{
    if(m_velocity.x > 0.0f)
    {
        m_velocity.x -= m_velocityMax/2*dt;
    }
    else if(m_velocity.x < 0.0f)
    {
        m_velocity.x += m_velocityMax/2*dt;
    }

    float tmp = m_velocity.x;

    if(tmp < 0.0f)
        tmp *= -1;

    if(tmp < 0.5f)
    {
        stopMovingToLeft();
        stopMovingToRight();
        stopMovementX();
    }
}

float RigidBody::getVelocityMax() {
    return m_velocityMax;
}
