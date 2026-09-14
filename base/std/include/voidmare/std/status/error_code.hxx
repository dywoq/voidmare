//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Status error code type definition
//

#ifndef _VOIDMARE_STD_STATUS_ERROR_CODE_HXX
#define _VOIDMARE_STD_STATUS_ERROR_CODE_HXX

namespace Voidmare::Std::Status
{
    //
    // Routine Description
    //
    // 		Identifies the type of a status. Its values are defined by other headers,
    // 		and returned by header's functionality. The error code's default value is 0,
    // 		which means "ok".
    //
    using ErrorCode = unsigned int;
} // namespace Voidmare::Std::Status

#endif
