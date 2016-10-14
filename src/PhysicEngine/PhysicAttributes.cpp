//
// Created by Kraghan on 12/10/2016.
//

#include "PhysicEngine/PhysicAttributes.hpp"

PhysicAttributes::PhysicAttributes(std::vector<Collider> const&colliders)
{
    m_colliders = colliders;
}

void PhysicAttributes::debug()
{
    for(unsigned i = 0; i < m_colliders.size(); ++i)
    {
        m_colliders[i].debug();
    }
}