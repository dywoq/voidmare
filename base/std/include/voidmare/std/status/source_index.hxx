//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Status source index enumeration
//

#ifndef _VOIDMARE_STD_STATUS_SOURCE_INDEX_HXX
#define _VOIDMARE_STD_STATUS_SOURCE_INDEX_HXX

namespace Voidmare::Std::Status
{
    //
    // Routine Description
    //
    // 		Identifies the source of a status instance. As a new header, which uses status functionality, appears,
    // 		his index shall be added here.
    //
    enum class SourceIndex : unsigned int
    {
        None = 0,
        Memory,
        PalMemory
    };
} // namespace Voidmare::Std::Status

#endif
