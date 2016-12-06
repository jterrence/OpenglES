#遍历第二章.cpp文件
file(GLOB chapter2files ${CMAKE_SOURCE_DIR}/Chapter_2/*.c)
add_executable(chapter2 ${chapter2files})
target_link_libraries(chapter2 ${TARGET_LIB})
