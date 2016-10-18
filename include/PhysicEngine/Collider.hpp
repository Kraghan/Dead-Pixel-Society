//
// Created by Kraghan on 12/10/2016.
//

#ifndef PROJECT_COLLIDER_HPP
#define PROJECT_COLLIDER_HPP


#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "PhysicObjectBase.hpp"
#include "RigidBody.hpp"

class Collider : public PhysicObjectBase{
public:
    Collider();

    void move(RigidBody* rigidBody);
};


#endif //PROJECT_COLLIDER_HPP
