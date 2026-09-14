//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Low-level services to manage memory. Their implementation depends on a platform.
//

#ifndef _VOIDMARE_STD_PAL_MEMORY_SERVICES_HXX
#define _VOIDMARE_STD_PAL_MEMORY_SERVICES_HXX

#include <voidmare/std/integer/aliases.hxx>
#include <voidmare/std/memory/shared/header.hxx>
#include <voidmare/std/status/error_code.hxx>
#include <voidmare/std/status/information.hxx>

namespace Voidmare::Std::Pal::Memory::Services
{
    enum ErrorCode : Status::ErrorCode
    {
        InvalidParameter,
        AllocationFailed,
        DestroyingFailed
    };

    //
    // Routine Description
    //
    // 		Requests a 4KiB page from a specific platform and writes the allocation information
    // 		to the provided memory header.
    //
    // Parameters
    //
    // 		DestinationHeader
    //
    // 			Where to write the allocation information.
    //
    // Error codes
    //
    // 		ErrorCode::InvalidParameter
    //
    // 			If DestinationHeader.VirtualAddress or DestinationHeader.RequestedSize are not 0.
    //
    // 		ErrorCode::AllocationFailed
    //
    // 			If the function failed to request a page.
    //
    Status::Information AllocatePage(::Voidmare::Std::Memory::Shared::Header &DestinationHeader) noexcept;

    //
    // Routine Description
    //
    // 		Frees the 4KiB page whose allocation information is stored in the provided header.
    //
    // Parameters
    //
    // 		DestinationHeader
    //
    // 			The page's allocation information, filled by the AllocatePage function.
    //
    // Error Codes
    //
    // 		ErrorCode::InvalidParameter
    //
    // 			If DestinationHeader.VirtualAddress is 0 or DestinationHeader.RequestedSize is not 4096.
    //
    // 		ErrorCode::DestroyingFailed
    //
    //			Freeing the page failed.
    //
    Status::Information DestroyPage(const ::Voidmare::Std::Memory::Shared::Header &SourceHeader) noexcept;
} // namespace Voidmare::Std::Pal::Memory::Services

#endif
