//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Unsigned integral constraint
//

#ifndef _VOIDMARE_STD_CONSTRAINTS_INTEGRAL_UNSIGNED_HXX
#define _VOIDMARE_STD_CONSTRAINTS_INTEGRAL_UNSIGNED_HXX

#include <voidmare/std/constraints/__internal/bool_constant.hxx>

namespace Voidmare::Std::Constraints
{
    namespace __Internal
    {
        template <typename T> struct UnsignedIntegral : BoolConstant<false>
        {
        };
        template <> struct UnsignedIntegral<unsigned char> : BoolConstant<true>
        {
        };
        template <> struct UnsignedIntegral<unsigned short> : BoolConstant<true>
        {
        };
        template <> struct UnsignedIntegral<unsigned int> : BoolConstant<true>
        {
        };
        template <> struct UnsignedIntegral<unsigned long long> : BoolConstant<true>
        {
        };
    } // namespace __Internal
    template <typename T>
    concept UnsignedIntegral = __Internal::UnsignedIntegral<T>::IsValid;
} // namespace Voidmare::Std::Constraints

#endif
