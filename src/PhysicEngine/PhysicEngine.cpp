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
    m_debugMode = false;
    m_drawn = false;
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

        // init
        Collider* colliderAssociated = getColliderAssociated(&m_rigidBody[i]);

        // Detect collision to set rigid body movement
        if(colliderAssociated != nullptr)
        {
            colliderAssociated->moveRigidBody(&m_rigidBody[i]);
            std::vector<Collision> collisions = collideWith(colliderAssociated);

            bool hasCollideDown = false, hasCollideLeft = false,
                    hasCollideRight = false;
            for(unsigned int j = 0; j < collisions.size(); ++j)
            {
                if(collisions[j].getCollisionSide() == Collision::DOWN)
                {
                    // Move collider
                    colliderAssociated->move(colliderAssociated->getPosition().x,
                                             colliderAssociated->getPosition().y+collisions[j].getDeep());
                    // Move rigid body
                    m_rigidBody[i].move(m_rigidBody[i].getPosition().x,
                                        m_rigidBody[i].getPosition().y+collisions[j].getDeep());
                    // Stop falling
                    m_rigidBody[i].setFalling(false);
                    m_rigidBody[i].stopMovementY();
                    hasCollideDown = true;
                }

                if(collisions[j].getCollisionSide() == Collision::LEFT)
                {
                    //std::cout<< collisions[j].getDeep() <<std::endl;
                    colliderAssociated->move(colliderAssociated->getPosition().x,
                                             colliderAssociated->getPosition().y);
                    // Move rigid body
                    m_rigidBody[i].move(m_rigidBody[i].getPosition().x,
                                        m_rigidBody[i].getPosition().y);
                    // Stop moving
                    //m_rigidBody[i].stopMovementX();
                    //hasCollideLeft = true;
                }

                if(collisions[j].getCollisionSide() == Collision::RIGHT)
                {
                    //std::cout<< collisions[j].getDeep() <<std::endl;
                    colliderAssociated->move(colliderAssociated->getPosition().x,
                                             colliderAssociated->getPosition().y);
                    // Move rigid body
                    m_rigidBody[i].move(m_rigidBody[i].getPosition().x,
                                        m_rigidBody[i].getPosition().y);
                    // Stop moving
                    //m_rigidBody[i].stopMovementX();
                    //hasCollideRight = true;
                }
            }

            if(!hasCollideDown)
            {
                m_rigidBody[i].setFalling(true);
                m_rigidBody[i].applyGravity(dt,m_gravity);
            }

            if(!hasCollideLeft && m_rigidBody[i].isMovingLeft())
            {
                m_rigidBody[i].goOnLeft(dt,hasCollideDown);
            }

            if(!hasCollideRight && m_rigidBody[i].isMovingRight())
            {
                m_rigidBody[i].goOnRight(dt,hasCollideDown);
            }
        }
        else
        {
            m_rigidBody[i].applyGravity(dt,m_gravity);
        }

        /*sf::Vector2f speed = m_rigidBody[i].getVelocity();
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

        if(m_rigidBody[i].isMovingLeft() && (colliderAssociated == nullptr ||
                !collidingLeft))
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


        if (isCollidingDown(colliderAssociated, &intersection,
                            m_rigidBody[i]
                                    .getVelocity()) && hasMoved)
        {
            m_rigidBody[i].move(m_rigidBody[i].getPosition().x,
                                m_rigidBody[i].getPosition().y -
                                intersection);
            if (colliderAssociated != nullptr)
            {
                colliderAssociated->move(
                        colliderAssociated->getPosition().x,
                        colliderAssociated->getPosition()
                                .y - intersection);
            }
        }

        if (isCollidingLeft(colliderAssociated, &intersection,
                            m_rigidBody[i]
                                    .getVelocity()) && hasMoved)
        {
            m_rigidBody[i].move(
                    m_rigidBody[i].getPosition().x + intersection,
                    m_rigidBody[i].getPosition().y);
            if (colliderAssociated != nullptr)
            {
                colliderAssociated->move(colliderAssociated->getPosition()
                                                 .x + intersection,
                                         colliderAssociated->getPosition().y);
            }
        }
        if (isCollidingRight(colliderAssociated, &intersection,
                             m_rigidBody[i]
                                     .getVelocity()) && hasMoved)
        {
            m_rigidBody[i].move(
                    m_rigidBody[i].getPosition().x - intersection,
                    m_rigidBody[i].getPosition().y);
            if (colliderAssociated != nullptr)
            {
                colliderAssociated->move(colliderAssociated->getPosition()
                                                 .x - intersection,
                                         colliderAssociated->getPosition().y);
            }
        }
        */
    }
    if(m_debugMode)
        debugDraw();
}

bool PhysicEngine::isCollidingDown(Collider* collider, float*
intersection, sf::Vector2f velocity)
{
    // Init
    sf::Vector2f pos = collider->getPosition();
    sf::Vector2f dimension = collider->getDimension();
    sf::Vector2f pointBottomLeft = sf::Vector2f(pos.x,pos.y+dimension.y+1.0f);
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x,
                                                 pos.y+dimension.y+1.0f);

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
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x,pos.y-1.0f);
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x+dimension.x,pos.y-1.0f);

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
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x+dimension.x+1.0f,pos.y);
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x+1.0f,
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
    sf::Vector2f pointBottomLeft = sf::Vector2f(pos.x-1.0f,pos.y+dimension.y);
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x-1.0f,pos.y);

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

std::vector<Collision> PhysicEngine::collideWith(Collider *collider)
{
    std::vector<Collision> collisions;

    sf::Vector2f pos = collider->getPosition();
    sf::Vector2f dimension = collider->getDimension();
    sf::Vector2f pointBottomLeft = sf::Vector2f(pos.x,pos.y+dimension.y);
    sf::Vector2f pointTopLeft = sf::Vector2f(pos.x,pos.y);
    sf::Vector2f pointTopRight = sf::Vector2f(pos.x+dimension.x,pos.y);
    sf::Vector2f pointBottomRight = sf::Vector2f(pos.x+dimension.x,pos.y+dimension.y);

    float intersection;
    for(unsigned i = 0; i < m_colliders.size(); ++i)
    {
        if(m_colliders[i].isFree() || !m_colliders[i].isReady())
            continue;

        if(m_colliders[i].getId() == collider->getId())
            continue;

        // Collide left
        if(m_colliders[i].getHitBox().contains(pointBottomLeft)
           || m_colliders[i].getHitBox().contains(pointTopLeft))
        {
            intersection = m_colliders[i].getPosition().x + dimension.x - pos.x;
            collisions.push_back(Collision(Collision::LEFT,&m_colliders[i],
                                           intersection));
        }

        // Collide right
        if(m_colliders[i].getHitBox().contains(pointBottomRight)
           || m_colliders[i].getHitBox().contains(pointTopRight))
        {
            intersection = m_colliders[i].getPosition().x - pos.x;
            collisions.push_back(Collision(Collision::RIGHT,&m_colliders[i],
                                           intersection));
        }

        // Collide top
        if(m_colliders[i].getHitBox().contains(pointTopRight)
           || m_colliders[i].getHitBox().contains(pointTopLeft))
        {
            intersection = m_colliders[i].getPosition().y+dimension.y - pos.y;
            collisions.push_back(Collision(Collision::UP,&m_colliders[i],
                                           intersection));
        }

        // Collide bottom
        if(m_colliders[i].getHitBox().contains(pointBottomLeft)
           || m_colliders[i].getHitBox().contains(pointBottomRight))
        {
            intersection = m_colliders[i].getPosition().y - dimension.y - pos.y;
            collisions.push_back(Collision(Collision::DOWN,&m_colliders[i],
                                           intersection));
        }
    }

    return collisions;

}

void PhysicEngine::debugMode(bool activate)
{
    m_debugMode = activate;
}

void PhysicEngine::debugDraw()
{
    if(!m_drawn)
    {
        for(unsigned int i = 0; i < m_colliders.size(); ++i)
        {
            if(m_colliders[i].isFree() || !m_colliders[i].isReady())
                continue;

            ConvexShape* c = m_ressourceManager->getConvexShape();
            c->setLayer(9);
            c->setWireColor(sf::Color::Cyan);
            c->setFillColor(sf::Color::Blue);
            c->setPointCount(4);
            c->setPoint(0,m_colliders[i].getPosition());

            c->setPoint(1,sf::Vector2f(m_colliders[i].getPosition().x
                                       +m_colliders[i].getDimension().x,
                                       m_colliders[i].getPosition().y));

            c->setPoint(2,m_colliders[i].getPosition()+m_colliders[i]
                    .getDimension());

            c->setPoint(3,sf::Vector2f(m_colliders[i].getPosition().x,
                                       m_colliders[i].getPosition().y
                                       +m_colliders[i].getDimension().y));
        }

        m_drawn = true;
    }

}