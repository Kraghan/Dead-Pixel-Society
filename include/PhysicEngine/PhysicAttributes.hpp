//
// Created by madjo on 12/10/2016.
//

#ifndef PROJECT_PHYSICATTRIBUTES_HPP
#define PROJECT_PHYSICATTRIBUTES_HPP

#include <vector>
#include <Dungeon/LayerData.hpp>
#include "Collider.hpp"

class PhysicAttributes {
private:
    std::vector<Collider> m_colliders;

public:
    PhysicAttributes(std::vector<Collider> const&colliders);

    void debug();

};


#endif //PROJECT_PHYSICATTRIBUTES_HPP
