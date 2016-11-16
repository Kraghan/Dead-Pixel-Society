//
// Created by madjo on 15/11/2016.
//

#ifndef PROJECT_COLLISION_HPP
#define PROJECT_COLLISION_HPP


#include "Collider.hpp"

class Collision
{
public:
    enum CollisionSide
    {
        UP,
        RIGHT,
        LEFT,
        DOWN
    };

    Collision(CollisionSide side, Collider* collider, float deep);
    Collider* getCollider();
    CollisionSide getCollisionSide();
    float getDeep();
private:
    Collider* m_collider;
    CollisionSide m_collisionSide;
    float m_deep;
};


#endif //PROJECT_COLLISION_HPP