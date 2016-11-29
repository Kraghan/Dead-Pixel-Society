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
    m_collideWith.reserve(15);
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

void Collider::addCollideWith(Collider *collider)
{
    if(!isInCollideWith(collider))
        m_collideWith.push_back(collider);
}

bool Collider::isInCollideWith(Collider *collider)
{
    for(auto c : m_collideWith)
    {
        if(c->getId() == collider->getId())
            return true;
    }
    return false;
}

std::vector<Collider *> Collider::getCollideWith()
{
    return m_collideWith;
}

void Collider::addCollideWith(std::vector<Collider *> colliders)
{
    for(unsigned int i = 0; i < colliders.size(); ++i)
    {
        addCollideWith(colliders[i]);
    }
}

void Collider::clearCollideWith()
{
    m_collideWith.clear();
}


