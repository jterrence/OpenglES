cmake_minimum_required(VERSION 3.6)
project(OpenglES)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static")

SET(EXECUTABLE_OUTPUT_PATH ${OpenglES_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${OpenglES_SOURCE_DIR}/lib)
SET(RUNTIME_OUTPUT_DIRECTORY ${OpenglES_SOURCE_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OpenglES_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OpenglES_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OpenglES_SOURCE_DIR}/bin)

#包含目录(外部链接)
include_directories(${CMAKE_SOURCE_DIR}/External/Include)
include_directories(${CMAKE_SOURCE_DIR}/Common/Include)

#包含第二章头文件
include_directories(${CMAKE_SOURCE_DIR}/Chapter_2/include)

#添加子目录
add_subdirectory(Common)

#设置链接库
set(TARGET_LIB
        ${CMAKE_SOURCE_DIR}/Library/libGLESv2.lib
        ${CMAKE_SOURCE_DIR}/Library/libEGL.lib
)

#遍历第二章.cpp文件
file(GLOB chapter2files ${CMAKE_SOURCE_DIR}/Chapter_2/*.cpp)
add_library(chapter2 ${chapter2files})
target_link_libraries(chapter2 Common ${TARGET_LIB})

set(SOURCE_FILES main.cpp)
add_executable(OpenglES ${SOURCE_FILES})
#链接库文件
target_link_libraries(OpenglES Common ${TARGET_LIB})