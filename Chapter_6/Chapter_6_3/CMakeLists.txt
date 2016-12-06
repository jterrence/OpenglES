cmake_minimum_required(VERSION 3.6)
file(GLOB chapter6_3files ${CMAKE_SOURCE_DIR}/Chapter_6/Chapter_6_3/*.c)
add_executable(Chapter_6_3 ${chapter6_3files})
target_link_libraries(Chapter_6_3 ${TARGET_LIB})


