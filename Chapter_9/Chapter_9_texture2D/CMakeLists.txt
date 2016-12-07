cmake_minimum_required(VERSION 3.6)
file(GLOB texture2Dfiles ${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_texture2D/*.c)
add_executable(Chapter_9_texture2D ${texture2Dfiles})
target_link_libraries(Chapter_9_texture2D ${TARGET_LIB})