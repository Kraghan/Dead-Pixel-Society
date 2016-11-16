//
// Created by Kraghan on 12/10/2016.
//

#ifndef PROJECT_COLLIDER_HPP
#define PROJECT_COLLIDER_HPP

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "PhysicObjectBase.hpp"
#include "RigidBody.hpp"

class TriggerAction;

class Collider : public PhysicObjectBase
{
public:
    Collider();

    void moveRigidBody(RigidBody* rigidBody);
    static void release(Collider* &collider);
    void setTrigger(TriggerAction* action);
    TriggerAction* getTriggerAction();

private:
    TriggerAction* m_triggerAction;
};


#endif //PROJECT_COLLIDER_HPP
