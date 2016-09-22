/*!
 * \brief    Contains the definition of
 *           type traits template
 *
 * \file     TypeTraits.hpp
 * \author   Aredhele
 * \version  0.1
 * \date     22/09/2016
 */
#ifndef __TYPE_TRAITS_HPP
#define __TYPE_TRAITS_HPP

#include <string>

/*!
 * \brief   The value isn't a string
 *          (passage by value)
 */
template <typename T>
struct Verify
{
    typedef T VerifiedType;
};

/*!
 * \brief   The value is smaller or equal than 32 bits
 *          but sizeof(std::string) will always return
 *          4 but it's actually not true
 *          so passage by const reference too
 */
template <>
struct Verify<std::string>
{
    typedef const std::string& VerifiedType;
};

/*!
 * \class   TypeTraits
 * \brief   Construct optimized function calls
 *          by detecting arguments type
 *
 */
template <typename T>
struct TypeTraits
{
    /*!
     * \brief   Define traits template
     */
    template <typename U, bool Size> struct TypeTraitImpl;

    /*!
     * \brief   Case where the arguments is bigger than 32 bits
     *          (taking argument by const reference)
     */
    template <typename U>
    struct TypeTraitImpl<U, true>
    {
        typedef const U& Type;
    };

    /*!
     * \brief   Case where the arguments is equal/smaller than 32 bits
     *          (taking argument by value)
     */
    template <typename U>
    struct TypeTraitImpl<U, false>
    {
        typedef typename Verify<U>::VerifiedType Type;
    };

    /*!
     * \brief   Call traits to check argument type
     */
    typedef typename TypeTraitImpl<T, (sizeof(T) > 4)>::Type TypeSize;
};

#endif // __TYPE_TRAITS_HPP