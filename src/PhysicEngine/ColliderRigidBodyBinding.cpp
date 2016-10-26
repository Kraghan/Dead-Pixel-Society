//
// Created by kraghan on 18/10/16.
//

#include "PhysicEngine/ColliderRigidBodyBinding.hpp"

ColliderRigidBodyBinding::ColliderRigidBodyBinding()
{
    m_rigidBody = nullptr;
    m_collider = nullptr;
}

ColliderRigidBodyBinding::ColliderRigidBodyBinding(Collider* collider, RigidBody* rigidBody)
{
    m_rigidBody = nullptr;
    m_collider = nullptr;
    init(collider,rigidBody);
}

void ColliderRigidBodyBinding::init(Collider* collider, RigidBody* rigidBody)
{
    m_collider = collider;
    m_rigidBody = rigidBody;
}

Collider* ColliderRigidBodyBinding::getCollider()
{
    return m_collider;
}

RigidBody* ColliderRigidBodyBinding::getRigidBody()
{
    return m_rigidBody;
}

bool ColliderRigidBodyBinding::hasCollider()
{
    return m_collider != nullptr;
}

bool ColliderRigidBodyBinding::hasRigidBody()
{
    return m_rigidBody != nullptr;
}

bool ColliderRigidBodyBinding::isFree()
{
    return m_isFree;
}

void ColliderRigidBodyBinding::setUsed()
{
    m_isFree = false;
}

void ColliderRigidBodyBinding::setFree()
{
   m_isFree = true;
}

void ColliderRigidBodyBinding::release(
        ColliderRigidBodyBinding* &colliderRigidBodyBinding) {
    colliderRigidBodyBinding->setFree();
    colliderRigidBodyBinding = nullptr;
}
