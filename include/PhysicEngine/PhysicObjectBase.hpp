//
// Created by madjo on 18/10/2016.
//

#ifndef PROJECT_PHYSICOBJECTBASE_HPP
#define PROJECT_PHYSICOBJECTBASE_HPP


#include <SFML/Graphics/Rect.hpp>

class PhysicObjectBase {
private:
    sf::IntRect m_hitBox;
    unsigned int m_size;
    bool m_isFree, m_isReady;
    unsigned int m_id;
public:
    PhysicObjectBase();

    void init(unsigned int x, unsigned int y, unsigned int
        width, unsigned int height, unsigned int size);

    bool isFree();

    sf::Vector2i getPosition();

    sf::Vector2u getDimension();

    sf::IntRect getHitBox();

    unsigned int getSize();

    void setUsed();

    void setFree();

    unsigned int getId();

    void setId(unsigned int id);
};


#endif //PROJECT_PHYSICOBJECTBASE_HPP
