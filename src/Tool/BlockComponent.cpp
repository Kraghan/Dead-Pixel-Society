//
// Created by madjo on 12/10/2016.
//

#include "Tool/BlockComponent.hpp"

BlockComponent::BlockComponent(std::string name,unsigned int size,unsigned int width,unsigned int height,
                               std::vector<LayerData> v_layerData,std::vector<Collider> v_collider)
: m_blockAttributes(name,size,width,height,v_layerData), m_physicAttributes(v_collider)
{

}

void BlockComponent::debug()
{
    m_blockAttributes.debug();
    m_physicAttributes.debug();
}