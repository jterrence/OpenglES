cmake_minimum_required(VERSION 3.6)
file(GLOB chapter7files ${CMAKE_SOURCE_DIR}/Chapter_7/*.c)
add_executable(Chapter_7 ${chapter7files})
target_link_libraries(Chapter_7 ${TARGET_LIB})