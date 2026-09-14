//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Memory functionality
//

#ifndef _VOIDMARE_STD_MEMORY_HXX
#define _VOIDMARE_STD_MEMORY_HXX

#include <voidmare/std/integer.hxx>

namespace Voidmare::Std::Memory
{
    //
    // Routine Description
    //
    // 		A centralized struct consisting of the allocated memory pointer's information,
    // 		such as its virtual address and requested size.
    //
    struct MemoryHeader
    {
        Integer::UInt64 VirtualAddress;
        Integer::UInt64 RequestedSize;
        constexpr explicit MemoryHeader(Integer::UInt64 ProvidedVirtualAddress,
                                        Integer::UInt64 ProvidedRequestedSize) noexcept
            : VirtualAddress(ProvidedVirtualAddress), RequestedSize(ProvidedRequestedSize)
        {
        }
    };
} // namespace Voidmare::Std::Memory

#endif
