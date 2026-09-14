#
# Copyright 2026 dywoq - All Rights Reserved
# https://github.com/dywoq/voidmare
#
# Module Description
#
# 		CmakeLists.txt file of the VoidmareStd module
#

cmake_minimum_required(VERSION 4.4.0)
project("VoidmareStd" CXX ASM)

file(GLOB_RECURSE PAL_SOURCES
	pal/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/*.cxx
	pal/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/*.S
)

add_library(${PROJECT_NAME} STATIC ${PAL_SOURCES})
target_compile_options(${PROJECT_NAME}
	PUBLIC --std=c++20 -fno-rtti -fno-exceptions -nostdlib
)
target_include_directories(${PROJECT_NAME}
	PUBLIC include/
	PRIVATE pal/include/
)

message(WARNING "System name: ${CMAKE_SYSTEM_NAME}")
message(WARNING "System processor: ${CMAKE_SYSTEM_PROCESSOR}")
