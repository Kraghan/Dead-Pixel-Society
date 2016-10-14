/*!
 * \brief   Header of the class TimeManager
 * \file    TimeManager.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    24/09/2016
 */

#ifndef __TIME_MANAGER_HPP
#define __TIME_MANAGER_HPP

class TimeManager
{
public:

    /*!
     * \brief
     */
    static float TimeScale;
    static constexpr float DefaultTimeScale = 1.0f;

    /*!
     * \brief   Constructor
     */
    explicit TimeManager();

    /*!
     * \brief   Destructor
     */
    virtual ~TimeManager();
};


#endif // __TIME_MANAGER_HPP