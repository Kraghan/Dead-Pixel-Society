//
// Created by Kraghan on 11/10/2016.
//

#ifndef PROJECT_BLOCKATTRIBUTES_HPP
#define PROJECT_BLOCKATTRIBUTES_HPP


#include <string>
#include <vector>
#include "Dungeon/LayerData.hpp"
#include <iostream>

class BlockAttributes {
private:
    std::string m_name;
    unsigned int m_spriteSize, m_width, m_height;
    std::vector<LayerData> m_spritesData;

public:
    BlockAttributes(std::string name, unsigned int spriteSize, unsigned int width, unsigned int height,
                    std::vector<LayerData> const&spriteDatas);

    const std::string &getName() const;

    unsigned int getSpriteSize() const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    const std::vector<LayerData> &getSpritesData() const;

    void debug();
};


#endif //PROJECT_BLOCKATTRIBUTES_HPP
