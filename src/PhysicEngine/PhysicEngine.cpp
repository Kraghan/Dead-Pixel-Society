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
    dt /= 1000;
    for(unsigned int i = 0; i < m_rigidBody.size(); ++i)
    {
        // No processing if rigidBody not used or not ready
        if(m_rigidBody[i].isFree() || !m_rigidBody[i].isReady())
            continue;

        // init
        Collider* colliderAssociated = getColliderAssociated(&m_rigidBody[i]);
        sf::Vector2f speed = m_rigidBody[i].getVelocity();
        bool collidingDown, collidingLeft,collidingRight,collidingUp, hasMoved;
        collidingDown = collidingRight = collidingLeft = collidingUp =
        hasMoved = false;
        float intersection;

        // Colission test
        if(isCollidingDown(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementY();
            collidingDown = true;
            m_rigidBody[i].setFalling(false);
        }

        if(isCollidingUp(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementY();
            collidingUp = true;
            m_rigidBody[i].setFalling(true);
        }

        if(isCollidingLeft(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementX();
            collidingLeft = true;
        }

        if(isCollidingRight(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementX();
            collidingRight = true;
        }

        if(colliderAssociated == nullptr || !collidingDown)
        {
            m_rigidBody[i].applyGravity(dt, m_gravity);
            hasMoved = true;
        }

        if(m_rigidBody[i].isMovingLeft() && (colliderAssociated == nullptr || !collidingLeft))
        {
            m_rigidBody[i].goOnLeft(dt,collidingDown);
            hasMoved = true;
        }

        if(m_rigidBody[i].isMovingRight() && (colliderAssociated == nullptr ||
                !collidingRight))
        {
            m_rigidBody[i].goOnRight(dt,collidingDown);
            hasMoved = true;
        }

        if(colliderAssociated != nullptr && hasMoved) {
            colliderAssociated->moveRigidBody(&m_rigidBody[i]);
        }

        if(isCollidingDown(colliderAssociated,&intersection,m_rigidBody[i]
                .getVelocity()) && hasMoved) {
            m_rigidBody[i].move(m_rigidBody[i].getPosition().x,
                                m_rigidBody[i].getPosition().y-intersection);
            if (colliderAssociated != nullptr)
            {
                colliderAssociated->move(colliderAssociated->getPosition().x,
                                         colliderAssociated->getPosition()
                                                 .y - intersection);
            }
        }

        if(isCollidingLeft(colliderAssociated,&intersection,m_rigidBody[i]
                .getVelocity()) && hasMoved) {
            m_rigidBody[i].move(m_rigidBody[i].getPosition().x+intersection,
                                m_rigidBody[i].getPosition().y);
            if (colliderAssociated != nullptr)
            {
                colliderAssociated->move(colliderAssociated->getPosition()
                                                 .x+intersection,
                                         colliderAssociated->getPosition().y);
            }
        }
        if(isCollidingRight(colliderAssociated,&intersection,m_rigidBody[i]
                .getVelocity()) && hasMoved) {
            m_rigidBody[i].move(m_rigidBody[i].getPosition().x-intersection,
                                m_rigidBody[i].getPosition().y);
            if (colliderAssociated != nullptr)
            {
                colliderAssociated->move(colliderAssociated->getPosition()
                                                 .x-intersection,
                                         colliderAssociated->getPosition().y);
            }
        }
    }
}

bool PhysicEngine::isCollidingDown(Collider* collider, float*
intersection, sf::Vector2f velocity)
{
    // Init
    sf::Vector2f pos = collider->getPosition();
    sf::Vector2f dimension = collider->getDimension();
    sf::Vector2f pointBottomLeft = sf::Vector2f(pos.x,pos.y+dimension.y+1);
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x,
                                                 pos.y+dimension.y+1);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().contains(pointBottomLeft)
           || m_colliders[i].getHitBox().contains(pointBottomRight))
        {
            *intersection = pointBottomLeft.y - m_colliders[i].getPosition().y;
            return true;
        }
    }
    return false;
}

bool PhysicEngine::isCollidingUp(Collider* collider, float*
intersection, sf::Vector2f velocity)
{
    // Init
    sf::Vector2f pos = collider->getPosition();
    sf::Vector2f dimension = collider->getDimension();
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x,pos.y-1);
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x+dimension.x,pos.y-1);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().contains(pointTopLeft)
           || m_colliders[i].getHitBox().contains(pointTopRight))
        {
            // TODO
            //*intersection = pointTopLeft.y - m_colliders[i].getPosition().y;
            return true;
        }
    }
    return false;
}

bool PhysicEngine::isCollidingRight(Collider* collider, float*
intersection, sf::Vector2f velocity)
{

    // Init
    sf::Vector2f pos = collider->getPosition();
    sf::Vector2f dimension = collider->getDimension();
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x+dimension.x+1,pos.y);
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x+1,
                                                 pos.y+dimension.y);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().contains(pointTopRight)
           || m_colliders[i].getHitBox().contains(pointBottomRight))
        {
            *intersection = pointTopRight.x - m_colliders[i].getPosition().x;
            return true;
        }
    }
    return false;
}

bool PhysicEngine::isCollidingLeft(Collider* collider, float*
intersection, sf::Vector2f velocity)
{

    // Init
    sf::Vector2f pos = collider->getPosition();
    sf::Vector2f dimension = collider->getDimension();
    sf::Vector2f pointBottomLeft = sf::Vector2f(pos.x-1,pos.y+dimension.y);
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x-1,pos.y);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().contains(pointBottomLeft)
           || m_colliders[i].getHitBox().contains(pointTopLeft))
        {
            *intersection = m_colliders[i].getPosition().x+dimension.x -
                    pointTopLeft.x;
            return true;
        }
    }
    return false;
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