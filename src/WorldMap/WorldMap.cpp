//
// Created by molipate on 11/10/16.
//

#include "../../include/WorldMap/WorldMap.hpp"
#include <cstdio>
#include <cstdlib>
#include <GraphicEngine/Sprite.hpp>

WorldMap::WorldMap(ResourceManager *m) {

    m_resourceManager = m;

    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            m_tab[i][j] = rand() % 2 + 1;
            printf("%d", m_tab[i][j]);
        }
        printf("\n");
    }

    for(int i = 0 ; i < 20 ; i++) {
        for (int j = 0; j < 10; j++) {

            m_s[i][j] = m_resourceManager->getSprite();
            m_s[i][j]->setTexture(*m_resourceManager->getTexture("FOREST"));

            if (m_tab[i][j] == 1)
                m_s[i][j]->setTextureRect(sf::Rect<int>(0, 0, 63, 63));
            if (m_tab[i][j] == 2)
                m_s[i][j]->setTextureRect(sf::Rect<int>(64, 64, 127, 127));

            m_s[i][j]->setPosition(j * 64, i * 64);
            m_s[i][j]->setLayer(0);
        }
    }
}

WorldMap::~WorldMap() {

    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 11; j++){
            Sprite::release(m_s[i][j]);
        }
    }
}