//
// Created by Kraghan on 12/10/2016.
//

#include "PhysicEngine/PhysicAttributes.hpp"

PhysicAttributes::PhysicAttributes() {

}


PhysicAttributes::PhysicAttributes(std::vector<Collider> const&colliders)
{
    m_colliders = colliders;
}

const std::vector<Collider> & PhysicAttributes::getColliders()const {
    return m_colliders;
}

