//
// Created by madjo on 15/11/2016.
//

#ifndef PROJECT_TRIGGERACTION_HPP
#define PROJECT_TRIGGERACTION_HPP


#include <PhysicEngine/Collider.hpp>

class TriggerAction {
public:
    TriggerAction();

    virtual void onTriggerEnter(Collider* collider);
    virtual void onTriggerExit(Collider* collider);
    virtual void onTriggerStay(Collider* collider);
};


#endif //PROJECT_TRIGGERACTION_HPP
