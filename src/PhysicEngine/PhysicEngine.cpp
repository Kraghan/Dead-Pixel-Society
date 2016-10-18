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

void PhysicEngine::init(ResourceManager* manager, unsigned int count_colliders,
                        unsigned int count_rigidBodies, float gravity)
{

}

void PhysicEngine::update(double dt)
{
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {

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

const RigidBody* PhysicEngine::getRigidBody()
{
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        if(m_rigidBody[i]->isFree())
        {
            m_rigidBody[i]->setUsed();
            return m_rigidBody[i];
        }
    }
}

bool PhysicEngine::isColliding(Collider* collider)
{

}