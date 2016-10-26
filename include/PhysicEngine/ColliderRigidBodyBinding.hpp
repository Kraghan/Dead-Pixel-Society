//
// Created by kraghan on 18/10/16.
//

#ifndef PROJECT_COLLIDERRIGIDBODYBINDING_HPP
#define PROJECT_COLLIDERRIGIDBODYBINDING_HPP

#include "Collider.hpp"
#include "RigidBody.hpp"

class ColliderRigidBodyBinding {
public:
    ColliderRigidBodyBinding();
    ColliderRigidBodyBinding(Collider* collider, RigidBody* rigidBody);
    void init(Collider* collider, RigidBody* rigidBody);

    Collider* getCollider();
    RigidBody* getRigidBody();

    bool hasCollider();
    bool hasRigidBody();
    bool isFree();
    void setUsed();
    void setFree();
    static void release(ColliderRigidBodyBinding* &colliderRigidBodyBinding);
private:
    Collider* m_collider;
    RigidBody* m_rigidBody;
    bool m_isFree;
};


#endif //PROJECT_COLLIDERRIGIDBODYBINDING_HPP
