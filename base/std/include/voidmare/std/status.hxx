//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Status definitions
//

#ifndef _VOIDMARE_STD_STATUS_HXX
#define _VOIDMARE_STD_STATUS_HXX

namespace Voidmare::Std::Status
{
    //
    // Routine Description
    //
    // 		Identifies the source of a status instance. As a new header, which uses status functionality, appears,
    // 		his index shall be added here.
    //
    enum class StatusSourceIndex : unsigned int
    {
        None = 0,
        Memory,
    };

    //
    // Routine Description
    //
    // 		Identifies the type of a status. Its values are defined by other headers,
    // 		and returned by header's functionality.
    //
    using StatusErrorCode = unsigned int;

    //
    // Routine Description
    //
    // 		Indicates the status of an operation.
    //
    struct Status
    {
        StatusSourceIndex SourceIndex = StatusSourceIndex::None;
        StatusErrorCode ErrorCode = 0;
        constexpr Status(StatusSourceIndex ProvidedSourceIndex, StatusErrorCode ProvidedErrorCode) noexcept
            : SourceIndex(ProvidedSourceIndex), ErrorCode(ProvidedErrorCode)
        {
        }
    };
} // namespace Voidmare::Std::Status

#endif
