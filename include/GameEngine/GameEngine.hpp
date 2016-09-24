/*!
 * \brief   Basic game engine like
 * \file    GameEngine.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    24/09/2016
 */

#ifndef __GAME_ENGINE_HPP
#define __GAME_ENGINE_HPP

#include "GameEngine/Clock.hpp"
#include <stdio.h>
/*!
 * \class   GameEngine
 * \brief   Handle the game loop and controls
 *          other engines
 *
 */
class GameEngine
{
public :

    /*!
     * \brief   Default Constructor
     */
    GameEngine();
    
    /*!
     * \brief   Default Destructor
     */
    virtual ~GameEngine();

    /*!
     * \brief   Initialize the game engine
     * \param
     * \return
     */
    void init();

    /*!
     * \brief   Start the game engine
     *          (Enter the game loop)
     */
    void start();

private :

    /*!
     * \brief   The state of the game loop
     */
    bool m_isRunning;

    /*!
     * \brief
     */
    const double MS_PER_UPDATE = 10.0;
};

#endif // __GAME_ENGINE_HPP