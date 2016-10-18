//
// Created by madjo on 18/10/2016.
//

#include "PhysicEngine/PhysicEngine.hpp"

PhysicEngine::PhysicEngine()
{
    // None
}

PhysicEngine::~PhysicEngine()
{

}

void PhysicEngine::init(ResourceManager* manager, unsigned int count_colliders,
                        unsigned int count_rigidBodies, unsigned int
                        count_rigidBodiesWithColliders, float gravity)
{
    m_ressourceManager = manager;
    m_colliders.reserve(count_colliders);
    m_rigidBody.reserve(count_rigidBodies);
    m_rigidBodiesWithColliders.reserve(count_rigidBodiesWithColliders);
    m_gravity = gravity;
}

void PhysicEngine::update(double dt)
{
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        Collider* collider = getColliderAssociated(m_rigidBody[i]);
        if(collider != nullptr)
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
            m_colliders[i]->setId(i);
            return m_colliders[i];
        }
    }
    return nullptr;
}

const RigidBody* PhysicEngine::getRigidBody()
{
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        if(m_rigidBody[i]->isFree())
        {
            m_rigidBody[i]->setUsed();
            m_rigidBody[i]->setId(i);
            return m_rigidBody[i];
        }
    }
    return nullptr;
}

ColliderRigidBodyBinding* PhysicEngine::bindRigidBodyAndCollider(RigidBody*
body, Collider*
collider)
{
    for(unsigned int i = 0; i < m_rigidBodiesWithColliders.size(); ++i)
    {
        if(m_rigidBodiesWithColliders[i]->isFree())
        {
            m_rigidBodiesWithColliders[i]->setUsed();
            m_rigidBodiesWithColliders[i]->init(collider,body);
            return m_rigidBodiesWithColliders[i];
        }
    }
    return nullptr;
}

bool PhysicEngine::isColliding(Collider* object)
{
    return false;
}

Collider* PhysicEngine::getColliderAssociated(RigidBody* rigidBody)
{
    for(unsigned int i = 0; i < m_rigidBodiesWithColliders.size();++i)
    {
        if(m_rigidBodiesWithColliders[i]->isFree())
            continue;

        if(m_rigidBodiesWithColliders[i]->getRigidBody()->getId() ==
                rigidBody->getId())
        {
            return m_rigidBodiesWithColliders[i]->getCollider();
        }
    }

    return nullptr;
}