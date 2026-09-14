//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
//		Internal bool constant definition
//

#ifndef _VOIDMARE_STD_CONSTRAINTS_INTERNAL_BOOL_CONSTANT_HXX
#define _VOIDMARE_STD_CONSTRAINTS_INTERNAL_BOOL_CONSTANT_HXX

namespace Voidmare::Std::Constraints::__Internal
{
    template <bool Valid> struct BoolConstant
    {
        constexpr static bool IsValid = Valid;
    };
} // namespace Voidmare::Std::Constraints::__Internal

#endif
