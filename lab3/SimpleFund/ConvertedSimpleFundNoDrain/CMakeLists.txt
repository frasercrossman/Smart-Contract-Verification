cmake_minimum_required(VERSION 3.8)
project(ConvertedSimpleFundNoDrain)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c contract_semantics.c)
add_executable(ConvertedSimpleFundNoDrain ${SOURCE_FILES})
