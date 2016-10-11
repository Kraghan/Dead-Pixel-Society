//
// Created by madjo on 11/10/2016.
//

#include "Dungeon/LayerData.hpp"

LayerData::LayerData(std::vector<char> const&layerData)
{
    m_layerData = layerData;
}


std::vector<char> const& LayerData::getLayerData()
{
    return m_layerData;
}