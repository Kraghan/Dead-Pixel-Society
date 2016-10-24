/*!
 * \brief   Header of the class Singleton
 * \file    Singleton.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    18/10/2016
 */

#ifndef __SINGLETON_HPP
#define __SINGLETON_HPP

template <typename T>
class Singleton
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit Singleton()
    {
        // None
    }

    static T * instance;
};

template <typename T> T * Singleton<T>::instance = nullptr;

#endif // __SINGLETON_HPP