//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Status source index enumeration
//

#ifndef _VOIDMARE_STD_STATUS_INFORMATION_HXX
#define _VOIDMARE_STD_STATUS_INFORMATION_HXX

#include <voidmare/std/status/error_code.hxx>
#include <voidmare/std/status/source_index.hxx>

namespace Voidmare::Std::Status
{
    //
    // Routine Description
    //
    // 		Contains the information of a status. It can be evaluated at compile time.
    //
    struct Information
    {
        SourceIndex CurrentSourceIndex = SourceIndex::Memory;
        ErrorCode CurrentErrorCode = 0;

        constexpr Information(SourceIndex ProvidedSourceIndex, ErrorCode ProvidedErrorCode)
            : CurrentSourceIndex(ProvidedSourceIndex), CurrentErrorCode(ProvidedErrorCode)
        {
        }

        //
        // Routine Description
        //
        // 		Checks if CurrentErrorCode is 0.
        //
        constexpr operator bool()
        {
            return CurrentErrorCode == 0;
        }
    };
} // namespace Voidmare::Std::Status

#endif
