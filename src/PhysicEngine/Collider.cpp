//
// Created by Kraghan on 12/10/2016.
//

#include "PhysicEngine/Collider.hpp"

Collider::Collider()
:PhysicObjectBase(){
    // None
}

void Collider::move(RigidBody* rigidBody)
{
    sf::Vector2f velocity = rigidBody->getVelocity();
    sf::Vector2i position = PhysicObjectBase::getPosition();

    PhysicObjectBase::move((int)(position.x+velocity.x),
                           (int)(position.y+velocity.y));
}