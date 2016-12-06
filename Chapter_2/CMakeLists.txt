cmake_minimum_required(VERSION 3.6)

#设置链接库，链接库文件一定要按此顺序，否则会出现链接不成功
#set(TARGET_LIB
#        Common
#        ${CMAKE_SOURCE_DIR}/Library/libGLESv2.lib
#        ${CMAKE_SOURCE_DIR}/Library/libEGL.lib
#)

#遍历第二章.cpp文件
file(GLOB chapter2files ${CMAKE_SOURCE_DIR}/Chapter_2/*.c)
add_executable(Chapter_2 ${chapter2files})
target_link_libraries(Chapter_2 ${TARGET_LIB})

#set(SOURCE_FILES Hello_Triangle.c)
#add_executable(OpenglES ${SOURCE_FILES})
#链接库文件
#target_link_libraries(OpenglES Common ${TARGET_LIB})