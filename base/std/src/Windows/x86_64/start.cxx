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
    // Exit the process
    //

    extern unsigned int ProgramEntry();
    auto ExitCode = IntegerBase<UINT>(ProgramEntry());
    ExitProcess(ExitCode.Value());
}
