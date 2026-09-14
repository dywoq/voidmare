//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Windows AMD64 Implementation of PAL page memory services
//

#define WIN32_LEAN_AND_MEAN
#include <voidmare/std/integer/aliases.hxx>
#include <voidmare/std/pal/memory/services.hxx>
#include <voidmare/std/status/error_code.hxx>
#include <voidmare/std/status/information.hxx>
#include <voidmare/std/status/source_index.hxx>
#include <windows.h>

namespace Voidmare::Std::Pal::Memory::Services
{
    Status::Information AllocatePage(::Voidmare::Std::Memory::Shared::Header &DestinationHeader) noexcept
    {
        Status::Information Information(Status::SourceIndex::PalMemory, 0);
        if (DestinationHeader.VirtualAddress != 0 || DestinationHeader.RequestedSize != 0)
        {
            return Information;
        }
        Integer::UInt64 RequestedSize = 4096;
        auto Address = VirtualAlloc(nullptr, RequestedSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
        if (!Address)
        {
            Information.CurrentErrorCode = ErrorCode::AllocationFailed;
            return Information;
        }
        DestinationHeader.VirtualAddress = (unsigned long long)Address;
        DestinationHeader.RequestedSize = RequestedSize;
        return Information;
    }

    Status::Information DestroyPage(const ::Voidmare::Std::Memory::Shared::Header &SourceHeader) noexcept
    {
        Status::Information Information(Status::SourceIndex::PalMemory, 0);
        if (SourceHeader.VirtualAddress == 0 || SourceHeader.RequestedSize != 4096)
        {
            Information.CurrentErrorCode = ErrorCode::InvalidParameter;
            return Information;
        }

        if (!VirtualFree((LPVOID)SourceHeader.VirtualAddress.Value(), SourceHeader.RequestedSize, MEM_DECOMMIT))
        {
            Information.CurrentErrorCode = ErrorCode::DestroyingFailed;
            return Information;
        }

        return Information;
    }
} // namespace Voidmare::Std::Pal::Memory::Services
