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
#include "Memory/ResourceManager.hpp"
#include "GraphicEngine/GraphicEngine.hpp"

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
     * \brief   Fixed update en render time
     *          16.67 = 60 fps
     */
    const double MS_PER_UPDATE = 16.67;

    /*!
     * \brief   The amazing graphic engine
     */
    GraphicEngine m_graphicEngine;

    /*!
     * \brief   The resource manager
     */
    ResourceManager m_resourceManager;

    /*!
     * \brief   A pointer on the graphic engine
     *          window
     */
    sf::RenderWindow * m_window;

    /*!
     * \brief   Start the game loop
     */
    void gameLoop();

    /*!
     * \brief   Process the user input
     *          in a non blocking way
     */
    void processInput();
};

#endif // __GAME_ENGINE_HPP