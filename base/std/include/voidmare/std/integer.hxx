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

namespace Voidmare::Std::Integer
{
    //
    // Routine Description
    //
    // 		This class is an unified way to manage integers at compile time,
    // 		providing a rich set of functionality.
    //
    template <typename IntegralT> class IntegerBase
    {
        //
        // TODO: When the standard library will have support of type traits,
        // add a compile time assertion that checks if IntegralT is integral type.
        //
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
        // 		Compilation process fails if the provided value is 0.
        //
        // Return
        //
        // 		Calculation result.
        //
        constexpr IntegralT Divide(IntegralT Value) noexcept
        {
            static_assert(Value != 0, "division by zero is forbidden");
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
