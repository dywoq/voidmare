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

file(GLOB_RECURSE SOURCES src/*.cxx src/*.S)
file(GLOB_RECURSE PAL_SOURCES
	src/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/*.cxx
	src/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}/*.S
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${PAL_SOURCES})
target_compile_options(${PROJECT_NAME}
	PUBLIC --std=c++20 -fno-rtti -fno-exceptions -nostdlib
)
target_include_directories(${PROJECT_NAME}
	PUBLIC include/
	PRIVATE src/include/
)
