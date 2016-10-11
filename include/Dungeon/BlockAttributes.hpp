//
// Created by madjo on 11/10/2016.
//

#ifndef PROJECT_BLOCKATTRIBUTES_HPP
#define PROJECT_BLOCKATTRIBUTES_HPP


#include <string>
#include <vector>

class BlockAttributes {
private:
    std::string m_name;
    unsigned int m_spriteSize, m_width, m_height;
    std::vector<char> m_spritesData;

public:
    BlockAttributes(std::string name, unsigned int spriteSize, unsigned int width, unsigned int height, std::vector<char> const&spriteDatas);

    const std::string &getName() const;

    unsigned int getSpriteSize() const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    const std::vector<char> &getSpritesData() const;
};


#endif //PROJECT_BLOCKATTRIBUTES_HPP
