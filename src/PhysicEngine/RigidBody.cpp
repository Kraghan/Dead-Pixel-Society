//
// Created by madjo on 18/10/2016.
//

#include "PhysicEngine/RigidBody.hpp"

RigidBody::RigidBody()
: PhysicObjectBase()
{

}

void RigidBody::init(unsigned int x, unsigned int y, unsigned int width,
                     unsigned int height, unsigned int size, float mass, float
                     velocity, float acceleration)
{
    PhysicObjectBase::init(x,y,width,height,size);
    m_mass = mass;
    m_velocity = velocity;
    m_acceleration = acceleration;
}

float RigidBody::getMass()
{
    return m_mass;
}

float RigidBody::getVelocity()
{
    return m_velocity;
}

float RigidBody::getAcceleration()
{
    return m_acceleration;
}