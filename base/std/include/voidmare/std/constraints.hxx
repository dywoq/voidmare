//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Constraints, replace type traits from the official C++ standard
// 		library
//

#ifndef _VOIDMARE_STD_CONSTRAINTS_HXX
#define _VOIDMARE_STD_CONSTRAINTS_HXX

namespace Voidmare::Std::Constraints
{
    namespace Internal
    {
        template <bool Valid> struct BoolConstant
        {
            constexpr static bool IsValid = Valid;
        };

        //
        // Integer-related
        //

        template <typename T> struct SignedIntegralConstraint : BoolConstant<false>
        {
        };
        template <> struct SignedIntegralConstraint<signed char> : BoolConstant<true>
        {
        };
        template <> struct SignedIntegralConstraint<signed short> : BoolConstant<true>
        {
        };
        template <> struct SignedIntegralConstraint<signed int> : BoolConstant<true>
        {
        };
        template <> struct SignedIntegralConstraint<signed long long> : BoolConstant<true>
        {
        };

        template <typename T> struct UnsignedIntegralConstraint : BoolConstant<false>
        {
        };
        template <> struct UnsignedIntegralConstraint<unsigned char> : BoolConstant<true>
        {
        };
        template <> struct UnsignedIntegralConstraint<unsigned short> : BoolConstant<true>
        {
        };
        template <> struct UnsignedIntegralConstraint<unsigned int> : BoolConstant<true>
        {
        };
        template <> struct UnsignedIntegralConstraint<unsigned long long> : BoolConstant<true>
        {
        };
    } // namespace Internal

    template <typename T>
    concept SignedIntegralConstraint = Internal::SignedIntegralConstraint<T>::IsValid;

    template <typename T>
    concept UnsignedIntegralConstraint = Internal::UnsignedIntegralConstraint<T>::IsValid;

    template <typename T>
    concept IntegralConstraint = SignedIntegralConstraint<T> || UnsignedIntegralConstraint<T>;
} // namespace Voidmare::Std::Constraints

#endif
