cmake_minimum_required(VERSION 3.0)

project(main)
set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)

set(SPIRIT_DOXYGEN_PROJECT_NAME ${CMAKE_PROJECT_NAME})

# My windows refuses to create the docs directory when given as absolute
# set(SPIRIT_DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# set(SPIRIT_DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs)

# Using relative path for docs instead works fine
set(SPIRIT_DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SPIRIT_DOXYGEN_OUTPUT_DIR test/docs)

add_subdirectory(.. ${CMAKE_CURRENT_BINARY_DIR}/Spirit-Doxygen)
