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
    for(unsigned int i = 0; i < m_colliders.capacity(); ++i)
    {
        m_colliders.push_back(Collider());
    }

    m_rigidBody.reserve(count_rigidBodies);
    for(unsigned int i = 0; i < m_rigidBody.capacity(); ++i)
    {
        m_rigidBody.push_back(RigidBody());
    }

    m_rigidBodiesWithColliders.reserve(count_rigidBodiesWithColliders);
    for(unsigned int i = 0; i < m_rigidBodiesWithColliders.capacity(); ++i)
    {
        m_rigidBodiesWithColliders.push_back(ColliderRigidBodyBinding());
    }
    m_gravity = gravity;
}

void PhysicEngine::update(double dt)
{
    dt /= 1000;
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        // No processing if rigidBody not used or not ready
        if(m_rigidBody[i].isFree() || !m_rigidBody[i].isReady())
            continue;

        // Calculate new velocities
        m_rigidBody[i].accelerate(m_gravity);
        std::cout<< m_rigidBody[i].getPosition().x << " " << m_rigidBody[i]
                .getPosition().y<< std::endl;

        // Calculate new positions
        m_rigidBody[i].moveAuto(dt);

        // Search associated collider
        Collider* collider = getColliderAssociated(&m_rigidBody[i]);
        if(collider != nullptr)
        {
            // Calculate new collider positions
            collider->moveRigidBody(&m_rigidBody[i],dt);

            // Testing collisions
            sf::FloatRect collision;
            Collider* collideWith = isColliding(collider,&collision);
            sf::Vector2f oldPos = collider->getPosition();
            while(collideWith != nullptr)
            {
                sf::Vector2f newPos = collider->getPosition();
                // Velocity x positive
                if(m_rigidBody[i].getVelocity().x > 0)
                {
                    newPos.x -= collision.width;
                }
                // Velocity x negative
                else if(m_rigidBody[i].getVelocity().x < 0)
                {
                    newPos.x += collision.width;
                }

                // Velocity y positive
                if(m_rigidBody[i].getVelocity().y > 0)
                {
                    newPos.y -= collision.height;
                }
                    // Velocity y negative
                else if(m_rigidBody[i].getVelocity().y < 0)
                {
                    newPos.y += collision.height;
                }

                collider->PhysicObjectBase::move(newPos.x, newPos.y);

                collideWith = isColliding(collider,&collision);
            }

            // Set new position to the rigidBody
            sf::Vector2f newColliderPos = collider->getPosition();
            float diffX = oldPos.x-newColliderPos.x;
            float diffY = oldPos.y-newColliderPos.y;

            m_rigidBody[i].move(m_rigidBody[i].getPosition().x-diffX,
                                 m_rigidBody[i].getPosition().y-diffY);

        }
    }
}

Collider* PhysicEngine::getCollider()
{
    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        if(m_colliders[i].isFree())
        {
            m_colliders[i].setUsed();
            m_colliders[i].setId(i);
            return &m_colliders[i];
        }
    }
    return nullptr;
}

RigidBody* PhysicEngine::getRigidBody()
{
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        if(m_rigidBody[i].isFree())
        {
            m_rigidBody[i].setUsed();
            m_rigidBody[i].setId(i);
            return &m_rigidBody[i];
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
        if(m_rigidBodiesWithColliders[i].isFree())
        {
            m_rigidBodiesWithColliders[i].setUsed();
            m_rigidBodiesWithColliders[i].init(collider,body);
            return &m_rigidBodiesWithColliders[i];
        }
    }
    return nullptr;
}

Collider* PhysicEngine::isColliding(Collider* collider,sf::FloatRect*
intersection)
{
    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().intersects(collider->getHitBox(),
                                                  *intersection))
        {
            return &m_colliders[i];
        }
    }
    return nullptr;
}

Collider* PhysicEngine::getColliderAssociated(RigidBody* rigidBody)
{
    for(unsigned int i = 0; i < m_rigidBodiesWithColliders.size();++i)
    {
        if(m_rigidBodiesWithColliders[i].isFree())
            continue;

        if(m_rigidBodiesWithColliders[i].getRigidBody()->getId() ==
                rigidBody->getId())
        {
            return m_rigidBodiesWithColliders[i].getCollider();
        }
    }

    return nullptr;
}