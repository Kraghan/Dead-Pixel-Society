//
// Created by madjo on 18/10/2016.
//

#ifndef PROJECT_PHYSICENGINE_HPP
#define PROJECT_PHYSICENGINE_HPP


#include <Memory/ResourceManager.hpp>
#include "GameEngine/Updatable.hpp"
#include "Collider.hpp"
#include "RigidBody.hpp"
#include "ColliderRigidBodyBinding.hpp"

class PhysicEngine : public Updatable{
public:
    PhysicEngine();

    virtual ~PhysicEngine();

    void init(ResourceManager* manager, unsigned int count_colliders,
              unsigned int count_rigidBodies, unsigned int
              count_rigidBodiesWithColliders, float gravity);

    virtual void update(double dt);

    Collider* getCollider();

    RigidBody* getRigidBody();

    bool isCollidingDown(Collider* collider, float* intersection,
                         sf::Vector2f velocity);

    bool isCollidingUp(Collider* collider, float* intersection,
                       sf::Vector2f velocity);

    bool isCollidingRight(Collider* collider, float* intersection,
                          sf::Vector2f velocity);

    bool isCollidingLeft(Collider* collider, float* intersection,
                         sf::Vector2f velocity);

    ColliderRigidBodyBinding* bindRigidBodyAndCollider(RigidBody* rigidBody,
                                                       Collider* collider);

    Collider* getColliderAssociated(RigidBody* rigidBody);
private:

    ResourceManager* m_ressourceManager;

    float m_gravity;

    std::vector<Collider> m_colliders;

    std::vector<RigidBody> m_rigidBody;

    std::vector<ColliderRigidBodyBinding> m_rigidBodiesWithColliders;
};
#endif //PROJECT_PHYSICENGINE_HPP
