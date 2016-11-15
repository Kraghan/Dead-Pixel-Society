/*!
 * \brief   Provide a way to get the current elapsed time
 * \file    Clock.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    24/09/2016
 */

#ifndef __CLOCK_HPP
#define __CLOCK_HPP

#include <ctime>
#include <SFML/System.hpp>

class Clock
{
public:
    /*!
     * \brief   Return the current time in milliseconds
     * \return  the current time in milliseconds
     */
    static double getCurrentTime();
};

#endif // __CLOCK_HPP