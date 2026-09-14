//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Signed integral constraint
//

#ifndef _VOIDMARE_STD_CONSTRAINTS_SAME_AS_HXX
#define _VOIDMARE_STD_CONSTRAINTS_SAME_AS_HXX

#include <voidmare/std/constraints/__internal/bool_constant.hxx>

namespace Voidmare::Std::Constraints
{
    namespace __Internal
    {
        template <typename T, typename U> struct SameAs : BoolConstant<false>
        {
        };
        template <typename T> struct SameAs<T, T> : BoolConstant<true>
        {
        };
    } // namespace __Internal
    template <typename T, typename U>
    concept SameAs = __Internal::SameAs<T, U>::IsValid;
} // namespace Voidmare::Std::Constraints

#endif
