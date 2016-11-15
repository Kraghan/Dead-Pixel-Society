//
// Created by madjo on 15/11/2016.
//

#include "PhysicEngine/PhysicTrigger.hpp"

PhysicTrigger::PhysicTrigger()
: Collider()
{
    m_isTrigger = false;
}

void PhysicTrigger::release(PhysicTrigger *&trigger)
{
    trigger->setFree();
    trigger = nullptr;
}

PhysicTrigger::~PhysicTrigger()
{

}
