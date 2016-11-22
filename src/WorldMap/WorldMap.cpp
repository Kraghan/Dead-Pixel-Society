//
// Created by molipate on 11/10/16.
//

#include "../../include/WorldMap/WorldMap.hpp"
#include <cstdio>
#include <cstdlib>
#include <GraphicEngine/Sprite.hpp>
#include <GraphicEngine/GraphicEngine.hpp>

WorldMap::WorldMap() {}

void WorldMap::init(ResourceManager *m) {

    m_resourceManager = m;

    if(GraphicEngine::background == nullptr)
        GraphicEngine::background = m_resourceManager->getSprite();

    GraphicEngine::background->setTexture(*m_resourceManager->getTexture("WORLDMAP"));
    GraphicEngine::background->setPosition(0.f, 0.f);
}

WorldMap::~WorldMap() {

    Sprite::release(m_background);
}