//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Signed integral constraint
//

#ifndef _VOIDMARE_STD_CONSTRAINTS_INTEGRAL_SIGNED_HXX
#define _VOIDMARE_STD_CONSTRAINTS_INTEGRAL_SIGNED_HXX

#include <voidmare/std/constraints/__internal/bool_constant.hxx>

namespace Voidmare::Std::Constraints
{
    namespace __Internal
    {
        template <typename T> struct SignedIntegral : BoolConstant<false>
        {
        };
        template <> struct SignedIntegral<signed char> : BoolConstant<true>
        {
        };
        template <> struct SignedIntegral<signed short> : BoolConstant<true>
        {
        };
        template <> struct SignedIntegral<signed int> : BoolConstant<true>
        {
        };
        template <> struct SignedIntegral<signed long long> : BoolConstant<true>
        {
        };
    } // namespace __Internal
    template <typename T>
    concept SignedIntegral = __Internal::SignedIntegral<T>::IsValid;
} // namespace Voidmare::Std::Constraints

#endif
