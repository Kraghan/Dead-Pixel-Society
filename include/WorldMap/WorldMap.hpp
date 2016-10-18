//
// Created by molipate on 11/10/16.
//

#ifndef PROJECT_WORLDMAP_HPP
#define PROJECT_WORLDMAP_HPP

#include <Memory/ResourceManager.hpp>

class WorldMap {

private:

    ResourceManager *m_resourceManager;

    Sprite *m_s[20][11];

    const int m_lengh = 200;
    const int m_height = 110;
    int m_tab[200][110];

public:
    WorldMap(ResourceManager *m);
    ~WorldMap();

};

#endif //PROJECT_WORLDMAP_HPP
