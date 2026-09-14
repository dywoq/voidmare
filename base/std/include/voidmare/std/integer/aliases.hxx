//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Aliases over the base integer class
//

#ifndef _VOIDMARE_STD_INTEGER_ALIASES_HXX
#define _VOIDMARE_STD_INTEGER_ALIASES_HXX

#include <voidmare/std/integer/base.hxx>

namespace Voidmare::Std::Integer
{
    using Int8 = Base<signed char>;
    using Int16 = Base<signed short>;
    using Int32 = Base<signed int>;
    using Int64 = Base<signed long long>;
    using UInt8 = Base<unsigned char>;
    using UInt16 = Base<unsigned short>;
    using UInt32 = Base<unsigned int>;
    using UInt64 = Base<unsigned long long>;
} // namespace Voidmare::Std::Integer

#endif
