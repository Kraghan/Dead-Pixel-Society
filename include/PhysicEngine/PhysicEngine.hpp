//
// Created by Kraghan on 18/10/2016.
//

#ifndef PROJECT_PHYSICENGINE_HPP
#define PROJECT_PHYSICENGINE_HPP


#include <Memory/ResourceManager.hpp>
#include "GameEngine/Updatable.hpp"
#include "Collider.hpp"
#include "RigidBody.hpp"
#include "ColliderRigidBodyBinding.hpp"
#include "Collision.hpp"

class PhysicEngine : public Updatable{
public:
    PhysicEngine();

    virtual ~PhysicEngine();

    void reset();

    void init(ResourceManager* manager, unsigned int count_colliders,
              unsigned int count_rigidBodies, unsigned int
              count_rigidBodiesWithColliders, float gravity);

    virtual void update(double dt);

    Collider* getCollider();

    RigidBody* getRigidBody();

    ColliderRigidBodyBinding* bindRigidBodyAndCollider(RigidBody* rigidBody,
                                                       Collider* collider);

    Collider* getColliderAssociated(RigidBody* rigidBody);

    std::vector<Collision> collideWith(Collider* collider, float velocityMax);

    unsigned int getColliderCount();

    unsigned int getRigidBodyCount();

    unsigned int getBindingCount();

    std::vector<Collider> getAllColliders();

    std::vector<RigidBody> getAllRigidBodies();

private:

    ResourceManager* m_ressourceManager;

    float m_gravity;

    std::vector<Collider> m_colliders;

    std::vector<RigidBody> m_rigidBody;

    std::vector<ColliderRigidBodyBinding> m_rigidBodiesWithColliders;

};
#endif //PROJECT_PHYSICENGINE_HPP
