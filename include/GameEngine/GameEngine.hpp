/*!
 * \brief   Basic game engine like
 * \file    GameEngine.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    24/09/2016
 */

#ifndef __GAME_ENGINE_HPP
#define __GAME_ENGINE_HPP

#include <Control/EventConverter.hpp>
#include "GameEngine/Game.hpp"
#include "GameEngine/Clock.hpp"
#include "GameEngine/TimeManager.hpp"

#include "Memory/ResourceLoader.hpp"
#include "Memory/ResourceManager.hpp"

#include "GraphicEngine/GraphicEngine.hpp"

#include "Control/ControlMap.hpp"

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
     * \brief   Fixed update (ups = update per second)
     *          16.67 =  60 ups
     *          11.11 =  90 ups
     *           8.33 = 120 ups
     *           4.16 = 240 ups
     */
    const double SECONDS_PER_UPDATE = 1.0 / 120.0;

    /*!
     * \brief   The amazing graphic engine
     */
    sf::RenderWindow * m_window;
    GraphicEngine m_graphicEngine;

    /*!
     * \brief   The more amazing physic engine
     */
    PhysicEngine m_physicEngine;

    /*!
     * \brief   The resource managers
     */
    ResourceLoader m_resourceLoader;
    ResourceManager m_resourceManager;

    /*!
     * \brief   The main class
     */
    Game m_game;

    /*!
     * \brief   The control mapping
     */
    ControlMap m_controlMap;

    /*!
     * \brief   The sfml event converter
     */
    EventConverter m_eventConverter;

    /*!
     * \brief   Start the game loop
     */
    void gameLoop();

    /*!
     * \brief   Process the user input
     *          in a non blocking way
     */
    void processInput();

    /*!
     * \brief   Update the game
     */
    void update();
};

#endif // __GAME_ENGINE_HPP