//
// Created by madjo on 15/11/2016.
//

#ifndef PROJECT_TRIGGER_HPP
#define PROJECT_TRIGGER_HPP


#include <Control/TriggerAction.hpp>
#include "Collider.hpp"

class PhysicTrigger : public Collider
{
public :
    PhysicTrigger();
    ~PhysicTrigger();

    static void release(PhysicTrigger* &trigger);
private:
    TriggerAction* m_triggerAction;
};


#endif //PROJECT_TRIGGER_HPP
