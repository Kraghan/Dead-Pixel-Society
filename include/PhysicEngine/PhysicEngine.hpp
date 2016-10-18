//
// Created by madjo on 18/10/2016.
//

#ifndef PROJECT_PHYSICENGINE_HPP
#define PROJECT_PHYSICENGINE_HPP


#include "GameEngine/Updatable.hpp"
#include "Collider.hpp"
#include "RigidBody.hpp"

class PhysicEngine : public Updatable{
public:
    PhysicEngine();
    virtual ~PhysicEngine();
    void init();

    virtual void update(double dt);

    const Collider* getCollider();

    const RigidBody* getSolidBody();

    bool isColliding(Collider* collider);
private:

    std::vector<Collider*> m_colliders;

    std::vector<RigidBody*> m_solidBody;
};
#endif //PROJECT_PHYSICENGINE_HPP
