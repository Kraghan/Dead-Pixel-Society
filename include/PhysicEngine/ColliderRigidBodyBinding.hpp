//
// Created by kraghan on 18/10/16.
//

#ifndef PROJECT_COLLIDERRIGIDBODYBINDING_HPP
#define PROJECT_COLLIDERRIGIDBODYBINDING_HPP


class ColliderRigidBodyBinding {
public:
    ColliderRigidBodyBinding();
    ColliderRigidBodyBinding(Collider* collider, RigidBody* rigidBody);
    void init(Collider* collider, RigidBody* rigidBody);

    Collider* getCollider();
    RigidBody* getRigidBody();

    bool hasCollider();
    bool hasRigidBody();
private:
    Collider* m_collider;
    RigidBody* m_rigidBody;
};


#endif //PROJECT_COLLIDERRIGIDBODYBINDING_HPP
