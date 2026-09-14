//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Signed integral constraint
//

#ifndef _VOIDMARE_STD_CONSTRAINTS_INTEGRAL_GENERAL_HXX
#define _VOIDMARE_STD_CONSTRAINTS_INTEGRAL_GENERAL_HXX

#include <voidmare/std/constraints/integral/signed.hxx>
#include <voidmare/std/constraints/integral/unsigned.hxx>

namespace Voidmare::Std::Constraints
{
    template <typename T>
    concept Integral = __Internal::SignedIntegral<T>::IsValid || __Internal::UnsignedIntegral<T>::IsValid;
} // namespace Voidmare::Std::Constraints

#endif
