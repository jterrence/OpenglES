cmake_minimum_required(VERSION 3.6)
file(GLOB cubemapfiles ${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_cubemap/*.c)
add_executable(Chapter_9_cubemap ${cubemapfiles})
target_link_libraries(Chapter_9_cubemap ${TARGET_LIB})