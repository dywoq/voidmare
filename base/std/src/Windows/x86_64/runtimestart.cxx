//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Starting routine of Windows x86_64
//

#include <windows.h>

extern "C" void VOIDMAREStd_RuntimeStart()
{
    extern void Main();
    Main();
    ExitProcess(1);
}
