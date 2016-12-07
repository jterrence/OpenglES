cmake_minimum_required(VERSION 3.6)
file(GLOB mipMap2Dfiles ${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_mipMap2D/*.c)
add_executable(Chapter_9_mipMap2D ${mipMap2Dfiles})
target_link_libraries(Chapter_9_mipMap2D ${TARGET_LIB})