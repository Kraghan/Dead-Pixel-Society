//
// Created by molipate on 11/10/16.
//

#include "../../include/WorldMap/WorldMap.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <GraphicEngine/Sprite.hpp>
#include <GraphicEngine/GraphicEngine.hpp>

WorldMap::WorldMap(){}

void WorldMap::init(ResourceManager *m) {

    m_resourceManager = m;

    for(int i = 0 ; i < 4 ; i++){
        m_spots.push_back(m_resourceManager->getSprite());
        m_spots[i]->setTexture(*m_resourceManager->getTexture("FOREST"));
        m_spots[i]->setTextureRect(sf::IntRect(0, 0, 64, 64));
        m_spots[i]->setLayer(1);
        m_spots[i]->setVisible(false); ///< TEMP
    }

    m_spots[0]->setPosition(sf::Vector2f(250, 125));
    m_spots[1]->setPosition(sf::Vector2f(1030, 125));
    m_spots[2]->setPosition(sf::Vector2f(250, 550));
    m_spots[3]->setPosition(sf::Vector2f(1030, 550));



    //Load clickable point
    /*std::string tmp;
    std::ifstream file("../../res/WorldMap/worldMap_clickablePoint.txt", std::ios::in);
    if(file){
        getline(file, tmp);
        std::cout << tmp << std::endl;
    }
    else {
        printf("Failed to load file");
        exit(-1);
    }
    file.close();*/

    update();
}

void WorldMap::update() {

    if(GraphicEngine::background == nullptr)
        GraphicEngine::background = m_resourceManager->getSprite();

    GraphicEngine::background->setTexture(*m_resourceManager->getTexture("WORLDMAP"));
    GraphicEngine::background->setPosition(0.f, 0.f);
}

WorldMap::~WorldMap() {

    //Release m_spots
}