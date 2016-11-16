//
// Created by Kraghan on 12/10/2016.
//

#include "PhysicEngine/Collider.hpp"
#include "Control/TriggerAction.hpp"

Collider::Collider()
:PhysicObjectBase()
{
    // None
    m_triggerAction = nullptr;
}

void Collider::moveRigidBody(RigidBody* rigidBody)
{
    sf::Vector2f velocity = rigidBody->getVelocity();
    sf::Vector2f position = PhysicObjectBase::getPosition();

    PhysicObjectBase::move(position.x+velocity.x,
                           position.y+velocity.y);
}

void Collider::release(Collider* &collider) {
    collider->setFree();
    collider = nullptr;
}

void Collider::setTrigger(TriggerAction *action)
{
    m_triggerAction = action;
}

TriggerAction *Collider::getTriggerAction()
{
    return m_triggerAction;
}