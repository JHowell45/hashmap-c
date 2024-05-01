cmake_minimum_required(VERSION 3.10)

project(hashmaps VERSION 0.1.0 LANGUAGES C)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/hashmaps/separate_chaining)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/hashmaps/open_addressing)