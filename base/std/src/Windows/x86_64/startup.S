//
// Copyright 2026 dywoq - All Rights Reserved
// https://github.com/dywoq/voidmare
//
// Module Description
//
// 		Initialization routine of Windows x86_64
//

.global mainCRTStartup
.extern VOIDMAREStd_WindowsStart

mainCRTStartup:

	//
	// Push the non-volatile registers onto the stack
	//

    push %rbx
    push %rbp
    push %rsi
    push %rdi
    push %r12
    push %r13
    push %r14
    push %r15

	//
	// Proceed to the next stage of starting routine,
	// reserving the shadow space
	//

	sub $40, %rsp
	call VOIDMAREStd_WindowsStart
