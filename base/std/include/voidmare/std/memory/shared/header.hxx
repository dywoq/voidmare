//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Memory header struct definition. It is shared between the PAL's and generic memory functionality.
//

#ifndef _VOIDMARE_STD_MEMORY_SHARED_HEADER_HXX
#define _VOIDMARE_STD_MEMORY_SHARED_HEADER_HXX

#include <voidmare/std/integer/aliases.hxx>

namespace Voidmare::Std::Memory::Shared
{
    //
    // Routine Description
    //
    // 		A centralized struct consisting of the allocated memory pointer's information
    //
    struct Header
    {
        Integer::UInt64 VirtualAddress = 0;
        Integer::UInt64 RequestedSize = 0;
        constexpr Header(Integer::UInt64 ProvidedVirtualAddress, Integer::UInt64 ProvidedRequestedSize)
            : VirtualAddress(ProvidedVirtualAddress), RequestedSize(ProvidedRequestedSize)
        {
        }
    };
} // namespace Voidmare::Std::Memory::Shared

#endif
