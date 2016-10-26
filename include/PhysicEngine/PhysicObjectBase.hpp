//
// Created by Kraghan on 18/10/2016.
//

#ifndef PROJECT_PHYSICOBJECTBASE_HPP
#define PROJECT_PHYSICOBJECTBASE_HPP


#include <SFML/Graphics/Rect.hpp>

class PhysicObjectBase {
private:
    sf::FloatRect m_hitBox;
    unsigned int m_size;
    bool m_isFree, m_isReady;
    unsigned int m_id;
public:
    PhysicObjectBase();

    void init(unsigned int x, unsigned int y, unsigned int
        width, unsigned int height, unsigned int size);

    bool isFree();

    bool isReady();

    sf::Vector2f getPosition();

    sf::Vector2f getDimension();

    sf::FloatRect getHitBox();

    unsigned int getSize();

    void setUsed();

    void setFree();

    unsigned int getId();

    void setId(unsigned int id);

    void move(float x, float y);
};


#endif //PROJECT_PHYSICOBJECTBASE_HPP
