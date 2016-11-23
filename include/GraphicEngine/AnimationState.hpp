/*!
 * \brief    File that contains the header of the class
 *           animation state
 * \file     AnimationState.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/11/2016
 */

#ifndef __ANIMATION_STATE_HPP
#define __ANIMATION_STATE_HPP

#include "GraphicEngine/Sprite.hpp"
#include "GameEngine/Updatable.hpp"

class AnimationState : public Updatable
{
public:

    /*!
     * \brief TODO
     */
    explicit AnimationState();

    /*!
     * \brief Initialize the state
     */
    void init(Sprite * pSrite, bool repeat,
              sf::Vector2i pos, sf::Vector2i size,
              int offset, char step, double delay);

    /*!
     * \brief Implements abstract method
     * \param dt The elapsed time
     */
    virtual void update(double dt);

    /*!
     * \brief TODO
     */
    void setRepeat(bool repeat);

    /*!
     * \brief TODO
     */
    void onEnter();

private:

    Sprite * m_sprite;

    bool m_repeat;
    sf::Vector2i m_size;
    sf::Vector2i m_position;

    char m_step;
    char m_currentStep;

    int m_offset;
    double m_delay;
    double m_elapsed;
};

#endif // __ANIMATION_STATE_HPP
