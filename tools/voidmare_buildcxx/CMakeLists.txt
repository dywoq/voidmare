#
# Copyright 2026 dywoq - All Rights Reserved
# https://github.com/dywoq/voidmare
#

cmake_minimum_required(VERSION 4.4.0)
project("voidmare_buildcxx")

file(GLOB_RECURSE SOURCES src/*.cxx)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_compile_options(${PROJECT_NAME} PRIVATE --std=c++20 -fno-exceptions -fno-rtti)
