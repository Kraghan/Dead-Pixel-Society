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

    virtual void init(unsigned int x, unsigned int y, unsigned int width,
                      unsigned int height, unsigned int size, float mass,
                      float acceleration, sf::Vector2f velocityMax);

    float getMass();

    sf::Vector2f getVelocity();

    float getAcceleration();

    void accelerate(float gravity);

    void moveAuto(double dt);
private:
    float m_mass, m_acceleration;
    sf::Vector2f m_velocity, m_velocityMax;
};


#endif //PROJECT_RIGIDBODY_HPP
