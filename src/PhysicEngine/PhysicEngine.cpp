//
// Created by Kraghan on 18/10/2016.
//

#include "PhysicEngine/PhysicEngine.hpp"

PhysicEngine::PhysicEngine()
{
    // None
}

PhysicEngine::~PhysicEngine()
{

}

void PhysicEngine::reset()
{
    for(unsigned int i = 0; i < m_rigidBodiesWithColliders.size(); ++i)
    {
        m_rigidBodiesWithColliders[i].setFree();
    }

    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        m_rigidBody[i].setFree();

    }

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        m_colliders[i].setFree();
    }
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
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        // No processing if rigidBody not used or not ready
        if(m_rigidBody[i].isFree() || !m_rigidBody[i].isReady())
            continue;

        if(m_rigidBody[i].isFalling())
            m_rigidBody[i].applyGravity(dt,m_gravity);

        if(m_rigidBody[i].isMovingLeft())
            m_rigidBody[i].goOnLeft(dt);

        if(m_rigidBody[i].isMovingRight())
            m_rigidBody[i].goOnRight(dt);

        // init
        Collider* colliderAssociated = getColliderAssociated(&m_rigidBody[i]);
        bool hasCollideDown = false, hasCollideLeft = false,
             hasCollideRight = false;

        // Detect collision to set rigid body movement
        if(colliderAssociated != nullptr )
        {
            sf::Vector2f oldPos = colliderAssociated->getPosition();
            std::vector<Collision> collisions = collideWith(colliderAssociated);
            if(colliderAssociated->getTriggerAction() == nullptr)
            {
                colliderAssociated->moveRigidBody(&m_rigidBody[i]);

                for (unsigned int j = 0; j < collisions.size(); ++j)
                {
                    if (collisions[j].getCollisionSide() == Collision::DOWN)
                    {
                        hasCollideDown = true;
                    }

                    if (collisions[j].getCollisionSide() == Collision::LEFT)
                    {
                        // Move collider
                        colliderAssociated->move(
                                colliderAssociated->getPosition().x
                                + collisions[j].getDeep(),
                                colliderAssociated->getPosition().y);
                        // Stop moving
                        hasCollideLeft = true;
                    }

                    if (collisions[j].getCollisionSide() == Collision::RIGHT)
                    {
                        // Move collider
                        colliderAssociated->move(
                                colliderAssociated->getPosition().x
                                + collisions[j].getDeep(),
                                colliderAssociated->getPosition().y);
                        // Stop moving
                        hasCollideRight = true;
                    }
                }

                if (!hasCollideLeft && !hasCollideRight)
                {
                    for (unsigned int j = 0; j < collisions.size(); ++j)
                    {
                        if (collisions[j].getCollisionSide() == Collision::DOWN)
                        {
                            // Move collider
                            colliderAssociated->move(
                                    colliderAssociated->getPosition().x,
                                    colliderAssociated->getPosition().y
                                    + collisions[j].getDeep());
                        }
                    }
                }

                sf::Vector2f offset = oldPos-colliderAssociated->getPosition();

                m_rigidBody[i].move(colliderAssociated->getPosition().x-offset.x,
                                    colliderAssociated->getPosition().y-offset.y);

            }
            else
            {
                std::vector<Collider *> colliders;
                for (unsigned int j = 0; j < collisions.size(); ++j)
                {
                    colliders.push_back(collisions[j].getCollider());
                    TriggerAction* triggerAction = collisions[j].getCollider()->getTriggerAction();

                    if(triggerAction != nullptr)
                    {
                        /*if(colliderAssociated->isInCollideWith(collisions[j]
                                                                        .getCollider()))
                            triggerAction->onTriggerStay(colliderAssociated);
                        else
                            triggerAction->onTriggerEnter(colliderAssociated);*/
                    }
                }

                for(auto c : colliderAssociated->getCollideWith())
                {
                    TriggerAction* triggerAction = c->getTriggerAction();

                    if(triggerAction != nullptr)
                    {
                        bool found = false;
                        for(unsigned int j = 0; j < colliders.size(); ++i)
                        {
                            if(colliders[i]->getId() == c->getId())
                            {
                                found = true;
                                break;
                            }
                        }
                        if(!found)
                        {
                            //triggerAction->onTriggerExit();
                        }
                    }
                }

                colliderAssociated->clearCollideWith();
                colliderAssociated->addCollideWith(colliders);
            }
        }

        if(!hasCollideDown)
        {
            m_rigidBody[i].setFalling(true);
        }
        else
        {
            m_rigidBody[i].setFalling(false);
            m_rigidBody[i].stopMovementY();
        }
        if(hasCollideLeft)
        {
            m_rigidBody[i].stopMovingToLeft();
        }
        if(hasCollideRight)
        {
            m_rigidBody[i].stopMovingToRight();
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
    body, Collider* collider)
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

std::vector<Collision> PhysicEngine::collideWith(Collider *collider)
{
    std::vector<Collision> collisions;

    sf::Vector2f pos = collider->getPosition();
    sf::Vector2f dimension = collider->getDimension();
    sf::Vector2f pointBottomLeft = sf::Vector2f(pos.x,pos.y+dimension.y);
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x,pos.y);
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x+dimension.x,pos.y);
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x,pos.y+dimension.y);

    float intersection, intersectionMax = 0.0f;
    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        if(m_colliders[i].isFree() || !m_colliders[i].isReady())
            continue;

        if(m_colliders[i].getId() == collider->getId())
            continue;

        // Collide top
        if((m_colliders[i].getHitBox().contains(pointTopRight)
           || m_colliders[i].getHitBox().contains(pointTopLeft))
           && m_colliders[i].getPosition().y + m_colliders[i].getDimension().y >= pos.y)
        {
            intersection = m_colliders[i].getPosition().y+dimension.y - pos.y;
            collisions.push_back(Collision(Collision::UP,&m_colliders[i],intersection));

            if(fabsf(intersection) > intersectionMax)
            {
                intersectionMax = intersection;
            }
        }

        // Collide bottom
        if((m_colliders[i].getHitBox().contains(pointBottomLeft)
           && m_colliders[i].getPosition().x + m_colliders[i].getDimension().x
              > pos.x )
           || (m_colliders[i].getHitBox().contains(pointBottomRight)
           && m_colliders[i].getPosition().x < pos.x + dimension.x))
        {
            intersection = m_colliders[i].getPosition().y - dimension.y - pos.y;
            collisions.push_back(Collision(Collision::DOWN,&m_colliders[i],intersection));
            if(fabsf(intersection) > fabsf(intersectionMax))
            {
                intersectionMax = intersection;
            }
        }
    }

    pointBottomLeft = sf::Vector2f(pos.x,
                                   pos.y + dimension.y + intersectionMax - 1.0f);
    pointTopLeft = sf::Vector2f(pos.x, pos.y + intersectionMax - 1.0f);
    pointTopRight = sf::Vector2f(pos.x + dimension.x,
                                 pos.y + intersectionMax - 1.0f);
    pointBottomRight = sf::Vector2f(pos.x  + dimension.x,
                                    pos.y + dimension.y + intersectionMax - 1.0f);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        if(m_colliders[i].isFree() || !m_colliders[i].isReady())
            continue;

        if(m_colliders[i].getId() == collider->getId())
            continue;

        // Collide left
        if (m_colliders[i].getHitBox().contains(pointBottomLeft)
            || m_colliders[i].getHitBox().contains(pointTopLeft))
        {
            intersection = m_colliders[i].getPosition().x
                           + m_colliders[i].getDimension().x
                           - pos.x;
            collisions.push_back(Collision(Collision::LEFT, &m_colliders[i],
                                           intersection));
        }

        // Collide right
        if (m_colliders[i].getHitBox().contains(pointBottomRight)
            || m_colliders[i].getHitBox().contains(pointTopRight))
        {
            intersection = m_colliders[i].getPosition().x - pos.x - dimension.x;
            collisions.push_back(Collision(Collision::RIGHT, &m_colliders[i],
                                           intersection));
        }
    }
    return collisions;

}

unsigned int PhysicEngine::getColliderCount()
{
    return (uint32_t)m_colliders.size();
}

unsigned int PhysicEngine::getRigidBodyCount() {
    return (uint32_t)m_rigidBody.size();
}

unsigned int PhysicEngine::getBindingCount() {
    return (uint32_t)m_rigidBodiesWithColliders.size();
}

std::vector<Collider> PhysicEngine::getAllColliders()
{
    return m_colliders;
}

std::vector<RigidBody> PhysicEngine::getAllRigidBodies()
{
    return m_rigidBody;
}
