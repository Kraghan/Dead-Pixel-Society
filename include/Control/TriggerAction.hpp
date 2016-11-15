//
// Created by madjo on 15/11/2016.
//

#ifndef PROJECT_TRIGGERACTION_HPP
#define PROJECT_TRIGGERACTION_HPP


#include <PhysicEngine/Collider.hpp>

class TriggerAction {
public:
    TriggerAction();

    virtual void onTriggerEnter(Collider* collider) = 0;
    virtual void onTriggerExit(Collider* collider) = 0;
    virtual void onTriggerStay(Collider* collider) = 0;
};


#endif //PROJECT_TRIGGERACTION_HPP
