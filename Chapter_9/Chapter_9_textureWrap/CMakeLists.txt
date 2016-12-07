cmake_minimum_required(VERSION 3.6)
file(GLOB textureWrapfiles ${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_textureWrap/*.c)
add_executable(Chapter_9_textureWrap ${textureWrapfiles})
target_link_libraries(Chapter_9_textureWrap ${TARGET_LIB})