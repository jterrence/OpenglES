cmake_minimum_required(VERSION 3.6)
file(GLOB noise3Dfiles ${CMAKE_SOURCE_DIR}/Chapter_14/Noise3D/*.c)
add_executable(Noise3D ${noise3Dfiles})
target_link_libraries(Noise3D ${TARGET_LIB})