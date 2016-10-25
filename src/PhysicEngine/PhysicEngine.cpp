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

        // init
        Collider* colliderAssociated = getColliderAssociated(&m_rigidBody[i]);
        sf::Vector2f speed = m_rigidBody[i].getVelocity();
        bool isMovingLeft = m_rigidBody[i].isMovingLeft();
        bool isMovingRight = m_rigidBody[i].isMovingRight();
        bool collidingDown, collidingLeft,collidingRight,collidingUp, hasMoved;
        collidingDown = collidingRight = collidingLeft = collidingUp =
        hasMoved = false;
        float intersection;

        // Colission test
        if(isCollidingDown(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementY();
            collidingDown = true;
            //std::cout << "Collide down "<<intersection <<std::endl;
        }

        if(isCollidingUp(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementY();
            collidingUp = true;
            //std::cout << "Collide up" <<std::endl;
        }

        if(isCollidingLeft(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementX();
            collidingLeft = true;
            //std::cout << "Collide left" <<std::endl;
        }

        if(isCollidingRight(colliderAssociated,&intersection,speed))
        {
            m_rigidBody[i].stopMovementX();
            collidingRight = true;
            //std::cout << "Collide right" <<std::endl;
        }

        if(colliderAssociated == nullptr || !collidingDown)
        {
            m_rigidBody[i].applyGravity(dt, m_gravity);
            hasMoved = true;
        }

        if(isMovingLeft && (colliderAssociated == nullptr || !collidingLeft))
        {
            m_rigidBody[i].goOnLeft(dt,collidingDown);
            hasMoved = true;
        }

        if(isMovingRight && (colliderAssociated == nullptr || !collidingRight))
        {
            m_rigidBody[i].goOnRight(dt,collidingDown);
            hasMoved = true;
        }

        if(colliderAssociated != nullptr && hasMoved) {
            colliderAssociated->moveRigidBody(&m_rigidBody[i]);
        }

        if(isCollidingDown(colliderAssociated,&intersection,m_rigidBody[i]
                .getVelocity())) {
            m_rigidBody[i].move(m_rigidBody[i].getPosition().x, m_rigidBody[i]
                                                                        .getPosition().y -
                                                                intersection);
            if (colliderAssociated != nullptr)
            {
                colliderAssociated->move(colliderAssociated->getPosition().x,
                                         colliderAssociated->getPosition()
                                                 .y - intersection);
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
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x,pos
                                                                           .y+dimension.y+1);

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
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x-1,pos.y);
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x-1+dimension.x,pos.y);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().contains(pointTopLeft)
           || m_colliders[i].getHitBox().contains(pointTopRight))
        {
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
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x+dimension.x,pos.y+1);
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x,pos
                                                                           .y+dimension.y+1);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().contains(pointTopRight)
           || m_colliders[i].getHitBox().contains(pointBottomRight))
        {
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
    sf::Vector2f pointBottomLeft = sf::Vector2f(pos.x,pos.y+dimension.y-1);
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x,pos.y-1);

    for(unsigned int i = 0; i < m_colliders.size(); ++i)
    {
        // Ignore if m_collider[i] == collider
        if(m_colliders[i].getId() == collider->getId())
            continue;

        if(m_colliders[i].getHitBox().contains(pointBottomLeft)
           || m_colliders[i].getHitBox().contains(pointTopLeft))
        {
            return true;
        }
    }
    return false;
}

/*
 // No processing if rigidBody not used or not ready
        if(m_rigidBody[i].isFree() || !m_rigidBody[i].isReady())
            continue;

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
                    //newPos.x -= collision.width;
                    m_rigidBody[i].stopMovementX();
                    m_rigidBody[i].stopMovingToLeft();
                }
                // Velocity x negative
                else if(m_rigidBody[i].getVelocity().x < 0)
                {
                    //newPos.x += collision.width;
                    m_rigidBody[i].stopMovementX();
                    m_rigidBody[i].stopMovingToRight();
                }

                // Velocity y positive
                if(m_rigidBody[i].getVelocity().y > 0)
                {
                    newPos.y -= collision.height;
                    m_rigidBody[i].stopMovementY();
                }
                    // Velocity y negative
                else if(m_rigidBody[i].getVelocity().y < 0)
                {
                    newPos.y += collision.height;
                    m_rigidBody[i].stopMovementY();
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

            std::cout<< m_rigidBody[i].getVelocity().x << " " << m_rigidBody[i]
                    .getVelocity().y<< std::endl;
        }

        // Calculate new velocities
        m_rigidBody[i].accelerate(m_gravity);

        // Calculate new positions
        m_rigidBody[i].moveAuto(dt);
 */

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