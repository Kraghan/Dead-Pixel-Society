//
// Created by Kraghan on 12/10/2016.
//

#ifndef PROJECT_COLLIDER_HPP
#define PROJECT_COLLIDER_HPP

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <unordered_set>
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
    void addCollideWith(Collider* collider);
    void addCollideWith(std::vector<Collider*> colliders);
    bool isInCollideWith(Collider* collider);
    std::vector<Collider*> getCollideWith();
    void clearCollideWith();

private:
    TriggerAction* m_triggerAction;
    std::vector<Collider*> m_collideWith;
};


#endif //PROJECT_COLLIDER_HPP
