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
        // No processing if rigidBody not used or not ready
        if(m_rigidBody[i]->isFree() || !m_rigidBody[i]->isReady())
        {
            continue;
        }

        // Calculate new velocities
        m_rigidBody[i]->accelerate(m_gravity);

        // Calculate new positions
        m_rigidBody[i]->move();

        // Search associated collider
        Collider* collider = getColliderAssociated(m_rigidBody[i]);
        if(collider != nullptr)
        {
            // Calculate new collider positions
            collider->move(m_rigidBody[i]);

            // Testing collisions
            sf::IntRect collision;
            Collider* collideWith = isColliding(collider,&collision);
            if(collideWith != nullptr)
            {
                sf::Vector2i newPos = collider->getPosition();
                if(collision.top == collider->getHitBox().top)
                {
                    newPos.y = 0;
                }
                else if(collision.top > collider->getHitBox().top)
                {
                    newPos.y = 0;
                }
                if(collision.left == collider->getHitBox().left)
                {
                    newPos.x = 0;
                }
                else if(collision.left > collider->getHitBox().left)
                {
                    newPos.x = 0;
                }
            }
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

Collider* PhysicEngine::isColliding(Collider* collider,sf::IntRect*
intersection)
{
    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i]->getId() == collider->getId())
            continue;

        if(m_colliders[i]->getHitBox().intersects(collider->getHitBox(),
                                                  *intersection))
        {
            return m_colliders[i];
        }
    }
    return nullptr;
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