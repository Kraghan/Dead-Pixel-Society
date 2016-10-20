//
// Created by madjo on 18/10/2016.
//

#ifndef PROJECT_RIGIDBODY_HPP
#define PROJECT_RIGIDBODY_HPP


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "PhysicObjectBase.hpp"

class RigidBody : public PhysicObjectBase{
public:
    RigidBody();

    virtual void init(unsigned int x, unsigned int y, unsigned int size, float
        mass, float acceleration, float velocityMax);

    float getMass();

    sf::Vector2f getVelocity();

    float getAcceleration();

    void applyGravity(double dt, float gravity);

    void accelerate();

    void moveAuto(double dt);

    void stopMovementX();

    void stopMovementY();

    void startMovingToLeft();

    void startMovingToRight();

    void stopMovingToLeft();

    void stopMovingToRight();
private:
    float m_mass, m_acceleration,m_velocityMax;
    sf::Vector2f m_velocity;
    bool toLeft, toRight;
};


#endif //PROJECT_RIGIDBODY_HPP
