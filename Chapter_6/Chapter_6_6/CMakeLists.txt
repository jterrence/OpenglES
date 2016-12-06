cmake_minimum_required(VERSION 3.6)
file(GLOB chapter6_6files ${CMAKE_SOURCE_DIR}/Chapter_6/Chapter_6_6/*.c)
add_executable(Chapter_6_6 ${chapter6_6files})
target_link_libraries(Chapter_6_6 ${TARGET_LIB})