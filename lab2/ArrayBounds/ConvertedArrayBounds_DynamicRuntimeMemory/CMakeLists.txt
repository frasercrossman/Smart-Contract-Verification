cmake_minimum_required(VERSION 3.8)
project(ConvertedArrayBounds_DynamicRuntimeMemory)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c contract_semantics.c)
add_executable(ConvertedArrayBounds_DynamicRuntimeMemory ${SOURCE_FILES})
target_link_libraries(ConvertedArrayBounds_DynamicRuntimeMemory m)