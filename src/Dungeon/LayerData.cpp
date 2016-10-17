#include "Dungeon/LayerData.hpp"

/* explicit */ LayerData::LayerData()
{
    // None
}

/* explicit */ LayerData::LayerData(std::vector<char> const&layerData)
{
    m_layerData = layerData;
}

/* virtual */ LayerData::~LayerData()
{
    // None
}

std::vector <char> const& LayerData::getLayerData()
{
    return m_layerData;
}


