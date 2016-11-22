//
// Created by molipate on 11/10/16.
//

#ifndef PROJECT_WORLDMAP_HPP
#define PROJECT_WORLDMAP_HPP

#include <Memory/ResourceManager.hpp>

class WorldMap {

private:

    ResourceManager *m_resourceManager;

    Sprite *m_background;

public:
    WorldMap();
    void init(ResourceManager *m);
    ~WorldMap();
};

#endif //PROJECT_WORLDMAP_HPP
