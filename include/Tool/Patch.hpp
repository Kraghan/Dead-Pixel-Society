/*!
 * \brief    Contains the header of the
 *           function to_string
 *
 * \file     Patch.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     13/10/2016
 */

#ifndef __PATCH_HPP
#define __PATCH_HPP

#include <sstream>

/*!
 * \brief  Patch gcc c++11 bug
 */
namespace fix
{
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream os;
        os << value;
        return os.str();
    }
}

#endif // __PATCH_HPP