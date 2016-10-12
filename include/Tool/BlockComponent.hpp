//
// Created by madjo on 12/10/2016.
//

#ifndef PROJECT_BLOCKCOMPONENT_HPP
#define PROJECT_BLOCKCOMPONENT_HPP

#include "PhysicEngine/PhysicAttributes.hpp"
#include "Dungeon/BlockAttributes.hpp"

class BlockComponent {
private:
    PhysicAttributes m_physicAttributes;
    BlockAttributes m_blockAttributes;
public:
    BlockComponent(std::string name,unsigned int size,unsigned int width,unsigned int height,
                   std::vector<LayerData> v_layerData,std::vector<Collider> v_collider);

    void debug();
};


#endif //PROJECT_BLOCKCOMPONENT_HPP
