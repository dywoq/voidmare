//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Functionality related to integers
//

#ifndef _VOIDMARE_STD_INTEGER_HXX
#define _VOIDMARE_STD_INTEGER_HXX

#include <voidmare/std/constraints.hxx>

namespace Voidmare::Std::Integer
{
    //
    // Routine Description
    //
    // 		This class is an unified way to manage integers at compile time,
    // 		providing a rich set of functionality.
    //
    template <Constraints::IntegralConstraint IntegralT> class IntegerBase
    {

      private:
        IntegralT m_Integer;

      public:
        constexpr explicit IntegerBase(IntegralT ProvidedInteger) noexcept : m_Integer(ProvidedInteger)
        {
        }

        //
        // Routine Description
        //
        // 		Increases the underlying integer.
        //
        constexpr void Increase() noexcept
        {
            m_Integer++;
        }

        //
        // Routine Description
        //
        // 		Decreases the underlying integer.
        //
        constexpr void Decrease() noexcept
        {
            m_Integer--;
        }

        //
        // Routine Description
        //
        // 		Returns the underlying integer.
        //
        [[nodiscard]] constexpr IntegralT Value() const noexcept
        {
            return m_Integer;
        }

        //
        // Routine Description
        //
        // 		Adds the provided value to the underlying integer.
        //
        // Return
        //
        // 		Calculation result.
        //
        constexpr IntegralT Add(IntegralT Value) noexcept
        {
            IntegralT Result = m_Integer + Value;
            m_Integer = Result;
            return Result;
        }

        //
        // Routine Description
        //
        // 		Subtracts the provided value from the underlying integer.
        //
        // Return
        //
        // 		Calculation result.
        //
        constexpr IntegralT Subtract(IntegralT Value) noexcept
        {
            IntegralT Result = m_Integer - Value;
            m_Integer = Result;
            return Result;
        }

        //
        // Routine Description
        //
        // 		Divides the underlying integer by the provided value.
        //
        // Return
        //
        // 		Calculation result.
        //
        constexpr IntegralT Divide(IntegralT Value) noexcept
        {
            IntegralT Result = m_Integer / Value;
            m_Integer = Result;
            return Result;
        }

        //
        // Routine Description
        //
        // 		Multiplies the underlying integer by the provided value.
        //
        // Return
        //
        // 		Calculation result.
        //
        constexpr IntegralT Multiply(IntegralT Value) noexcept
        {
            IntegralT Result = m_Integer * Value;
            m_Integer = Result;
            return Result;
        }

        //
        // Routine Description
        //
        // 		Provides the absolute value of the underlying integer.
        //
        constexpr IntegralT Absolute()
        {
            if (m_Integer >= 0)
            {
                return m_Integer;
            }
            return -m_Integer;
        }

        //
        // Routine Description
        //
        // 		This structure specifies numeric limits of the provided integral type,
        // 		such as its minimum and maximum value.
        //
        struct Limits
        {
            constexpr static IntegralT Minimum = 0;
            constexpr static IntegralT Maximum = 0;
        };
    };

    //
    // Constant definitions of the IntegerBase::Limits structure
    //

    template <> struct IntegerBase<signed char>::Limits
    {
        constexpr static signed char Minimum = -128;
        constexpr static signed char Maximum = 127;
    };

    template <> struct IntegerBase<signed short>::Limits
    {
        constexpr static signed short Minimum = -32768;
        constexpr static signed short Maximum = 32767;
    };

    template <> struct IntegerBase<signed int>::Limits
    {
        constexpr static signed int Minimum = -2147483648;
        constexpr static signed int Maximum = 2147483647;
    };

    template <> struct IntegerBase<signed long long>::Limits
    {
        constexpr static signed long long Minimum = -9223372036854775807LL - 1;
        constexpr static signed long long Maximum = 9223372036854775807LL;
    };

    template <> struct IntegerBase<unsigned char>::Limits
    {
        constexpr static unsigned char Minimum = 0;
        constexpr static unsigned char Maximum = 255;
    };

    template <> struct IntegerBase<unsigned short>::Limits
    {
        constexpr static unsigned short Minimum = 0;
        constexpr static unsigned short Maximum = 65535;
    };

    template <> struct IntegerBase<unsigned int>::Limits
    {
        constexpr static unsigned int Minimum = 0;
        constexpr static unsigned int Maximum = 4294967295U;
    };

    template <> struct IntegerBase<unsigned long long>::Limits
    {
        constexpr static unsigned long long Minimum = 0;
        constexpr static unsigned long long Maximum = 18446744073709551615ULL;
    };

    //
    // Type wrappers around integral types
    //

    using Int8 = IntegerBase<signed char>;
    using Int16 = IntegerBase<signed short>;
    using Int32 = IntegerBase<signed int>;
    using Int64 = IntegerBase<signed long long>;
    using UInt8 = IntegerBase<unsigned char>;
    using UInt16 = IntegerBase<unsigned short>;
    using UInt32 = IntegerBase<unsigned int>;
    using UInt64 = IntegerBase<unsigned long long>;
} // namespace Voidmare::Std::Integer

#endif
