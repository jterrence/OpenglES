cmake_minimum_required(VERSION 3.6)
file(GLOB chapter2files ${CMAKE_SOURCE_DIR}/Chapter_2/*.c)
add_executable(Chapter_2 ${chapter2files})
target_link_libraries(Chapter_2 ${TARGET_LIB})