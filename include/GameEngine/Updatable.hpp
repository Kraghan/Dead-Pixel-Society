/*!
 * \brief   Abstract class for all updatable objects
 * \file    Updatable.hpp
 * \author  Aredhele
 * \version 0.1
 * \date    24/09/2016
 */

#ifndef __UPDATABLE_HPP
#define __UPDATABLE_HPP

class Updatable
{
public:

    /*!
     * \brief   Abstract method for updatable objects
     * \param
     */
    virtual void update(double dt) = 0;
};

#endif // __UPDATABLE_HPP
