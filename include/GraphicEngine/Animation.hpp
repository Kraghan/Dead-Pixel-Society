/*!
 * \brief    File that contains the header of the class Animation
 * \file     Animation.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/11/2016
 */

#ifndef __ANIMATION_HPP
#define __ANIMATION_HPP

#include <map>
#include "GameEngine/Updatable.hpp"
#include "GraphicEngine/AnimationState.hpp"

class Animation : public Updatable
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Animation();

    /*!
     * \brief   Default destructor
     */
    virtual ~Animation();

    /*!
     * \brief Implements abstract method
     * \param dt The elapsed time
     */
    virtual void update(double dt);

    /*!
     * \brief Add a state to the map
     * @param state
     */
    void addState(std::string const&& key, AnimationState const&& state);

    /*
     * \brief TODO
     */
    AnimationState * getState(std::string const& key);

    /*!
     * \brief Utilitary methods
     */
    void setState(std::string const& key);
    void pause();
    void start();

private:

    bool m_play;
    AnimationState * m_currentState;
    std::map < std::string, AnimationState > m_stateList;
};

#endif // __ANIMATION_HPP