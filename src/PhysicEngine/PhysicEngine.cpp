//
// Created by madjo on 18/10/2016.
//

#include "PhysicEngine/PhysicEngine.hpp"

PhysicEngine::PhysicEngine()
{

}

PhysicEngine::~PhysicEngine()
{

}

void PhysicEngine::init()
{

}

void PhysicEngine::update(double dt)
{
    for(unsigned int i = 0; i < m_solidBody.size(); ++i)
    {
        if()
        {

        }
    }
}

const Collider* PhysicEngine::getCollider()
{
    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        if(m_colliders[i]->isFree())
        {
            m_colliders[i]->setUsed();
            return m_colliders[i];
        }
    }
}

const RigidBody* PhysicEngine::getSolidBody()
{
    for(unsigned int i = 0; i < m_solidBody.size(); ++i)
    {
        if(m_solidBody[i]->isFree())
        {
            m_solidBody[i]->setUsed();
            return m_solidBody[i];
        }
    }
}

bool PhysicEngine::isColliding(Collider* collider)
{

}