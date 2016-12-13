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
    bool m_isFree, m_isReady, m_isEnabled;
    unsigned int m_id;
public:
    PhysicObjectBase();

    void init(float x, float y, float width, float height, unsigned
                int size);

    bool isFree();

    bool isReady();

    bool isEnabled();

    sf::Vector2f getPosition()const;

    sf::Vector2f getDimension()const;

    sf::FloatRect getHitBox();

    unsigned int getSize()const;

    void setUsed();

    void setFree();

    void enable();

    void disable();

    unsigned int getId();

    void setId(unsigned int id);

    void move(float x, float y);
};


#endif //PROJECT_PHYSICOBJECTBASE_HPP
