//
// Created by madjo on 11/10/2016.
//

#ifndef PROJECT_LAYERDATA_HPP
#define PROJECT_LAYERDATA_HPP


#include <vector>

class LayerData {
private:
    std::vector<char> m_layerData;
    unsigned int m_layer;
public:
    LayerData(unsigned int layer, std::vector<char> const&layerData);
    const unsigned int getLayerId();
    std::vector<char> const &getLayerData();
};


#endif //PROJECT_LAYERDATA_HPP
