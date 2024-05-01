cmake_minimum_required(VERSION 3.10)

project(separate_chaining_hashmap)

set(LIBRARY_NAME hashmap)
set(BUCKET_EXAMPLE bucket_test)
set(HASHMAP_EXAMPLE hashmap_test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${LIBRARY_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bucket.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hashmap.c
)

add_executable(${BUCKET_EXAMPLE} ${CMAKE_CURRENT_SOURCE_DIR}/example/bucket_test.c)
target_link_libraries(${BUCKET_EXAMPLE} ${LIBRARY_NAME})

add_executable(${HASHMAP_EXAMPLE} ${CMAKE_CURRENT_SOURCE_DIR}/example/hashmap_test.c)
target_link_libraries(${HASHMAP_EXAMPLE} ${LIBRARY_NAME})