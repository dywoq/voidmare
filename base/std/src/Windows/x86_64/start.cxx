//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Starting routine of Windows x86_64
//

#include <voidmare/std/integer.hxx>
#include <windows.h>

extern "C" void VoidmareStd___WindowsStart()
{
    using namespace Voidmare;
    using namespace Std::Integer;

    //
    // Initialization routine
    //

    //
    // Call the main function.
    //

    extern void Main();
    Main();

    //
    // Exit the process
    //

    auto ExitCode = IntegerBase<UINT>(0);
    ExitProcess(ExitCode.Value());
}
