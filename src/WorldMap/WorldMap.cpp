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
            m_tab[i][j] = 0;//rand() % 2 + 1;
            printf("%d", m_tab[i][j]);

            Sprite *s = m_resourceManager->getSprite();
            s->setTexture(*m_resourceManager->getTexture("FOREST"));
            if(m_tab[i][j] == 1)
                s->setTextureRect(sf::Rect<int>(0, 0, 63, 63));
            if(m_tab[i][j] == 2)
                s->setTextureRect(sf::Rect<int>(64, 64, 127, 127));

            s->setPosition(i * 64, j * 64);

            s->setLayer(0);
        }
        printf("\n");
    }
}
