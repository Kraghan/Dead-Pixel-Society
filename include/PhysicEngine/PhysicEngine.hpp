//
// Created by madjo on 18/10/2016.
//

#ifndef PROJECT_PHYSICENGINE_HPP
#define PROJECT_PHYSICENGINE_HPP


#include <Memory/ResourceManager.hpp>
#include "GameEngine/Updatable.hpp"
#include "Collider.hpp"
#include "RigidBody.hpp"

class PhysicEngine : public Updatable{
public:
    PhysicEngine();

    virtual ~PhysicEngine();

    void init(ResourceManager* manager, unsigned int count_colliders,
              unsigned int count_rigidBodies, float gravity);

    virtual void update(double dt);

    const Collider* getCollider();

    const RigidBody* getRigidBody();

    bool isColliding(Collider* collider);


private:

    std::vector<Collider*> m_colliders;

    std::vector<RigidBody*> m_rigidBody;
};
#endif //PROJECT_PHYSICENGINE_HPP
