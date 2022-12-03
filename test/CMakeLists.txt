cmake_minimum_required(VERSION 3.0)

project(main)
set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)

set(SPIRIT_DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SPIRIT_DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs)

# (Copy paste Spirit-Doxygen in a subdir first)
add_subdirectory(Spirit-Doxygen)
