//
// Created by madjo on 11/10/2016.
//

#include "Dungeon/LayerData.hpp"

LayerData::LayerData(unsigned int layer, std::vector<char> const&layerData)
{
    m_layer = layer;
    m_layerData = layerData;
}

const unsigned int LayerData::getLayerId()
{
    return m_layer;
}

std::vector<char> const& LayerData::getLayerData()
{
    return m_layerData;
}