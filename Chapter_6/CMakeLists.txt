cmake_minimum_required(VERSION 3.6)
file(GLOB chapter6files ${CMAKE_SOURCE_DIR}/Chapter_6/*.c)
add_executable(Chapter_6 ${chapter6files})
target_link_libraries(Chapter_6 ${TARGET_LIB})