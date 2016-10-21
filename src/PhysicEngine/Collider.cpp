//
// Created by Kraghan on 12/10/2016.
//

#include "PhysicEngine/Collider.hpp"

Collider::Collider()
:PhysicObjectBase(){
    // None
}

void Collider::moveRigidBody(RigidBody* rigidBody,double dt)
{
    sf::Vector2f velocity = rigidBody->getVelocity();
    sf::Vector2f position = PhysicObjectBase::getPosition();

    // Why ?
    PhysicObjectBase::move(position.x-(float)(velocity.x*dt),
                           position.y+(float)(velocity.y*dt));
}