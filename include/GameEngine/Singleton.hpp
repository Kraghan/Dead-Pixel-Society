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
protected:
    static T * m_instance;
    Singleton() {};

public:

    static T * Instance()
    {
        if(m_instance == nullptr)
            m_instance = new T();

        return m_instance;
    }
};

template <typename T> T * Singleton<T>::m_instance = nullptr;

#endif // __SINGLETON_HPP