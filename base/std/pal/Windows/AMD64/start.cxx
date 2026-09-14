//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Starting routine of Windows AMD64
//

#include <voidmare/std/integer/base.hxx>
#include <windows.h>

extern "C" void VoidmareStd___WindowsStart()
{
    using namespace Voidmare::Std;

    //
    // Initialization routine
    //

    //
    // Exit the process
    //

    extern unsigned int ProgramEntry();
    auto ExitCode = Integer::Base<UINT>(ProgramEntry());
    ExitProcess(ExitCode);
}
