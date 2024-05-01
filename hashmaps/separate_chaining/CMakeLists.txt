cmake_minimum_required(VERSION 3.10)

project(separate_chaining_hashmap)

set(LIBRARY_NAME hashmap)
set(EXAMPLE_NAME hashmap_test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${LIBRARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bucket.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hashmap.c
)

add_executable(${EXAMPLE_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/example/main.c
)

target_link_libraries(${EXAMPLE_NAME} ${LIBRARY_NAME})