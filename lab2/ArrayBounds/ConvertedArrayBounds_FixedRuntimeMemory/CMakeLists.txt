cmake_minimum_required(VERSION 3.8)
project(ConvertedArrayBounds_FixedRuntimeMemory)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c contract_semantics.c)
add_executable(ConvertedArrayBounds_FixedRuntimeMemory ${SOURCE_FILES})