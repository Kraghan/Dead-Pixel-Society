//
// Created by madjo on 15/11/2016.
//

#include "PhysicEngine/Collision.hpp"

Collider *Collision::getCollider()
{
    return m_collider;
}

Collision::CollisionSide Collision::getCollisionSide()
{
    return m_collisionSide;
}

float Collision::getDeep()
{
    return m_deep;
}

Collision::Collision(Collision::CollisionSide side, Collider *collider,
                     float deep)
{
    m_collider = collider;
    m_collisionSide = side;
    m_deep = deep;
}
