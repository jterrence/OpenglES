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

#包含目录
include_directories(${CMAKE_SOURCE_DIR}/External/Include)
include_directories(${CMAKE_SOURCE_DIR}/Common/Include)

#添加子目录
add_subdirectory(Common)

#设置链接库
set(TARGET_LIB
        ${CMAKE_SOURCE_DIR}/Library/libGLESv2.lib
        ${CMAKE_SOURCE_DIR}/Library/libEGL.lib
)
set(SOURCE_FILES Hello_Triangle.c)
add_executable(OpenglES ${SOURCE_FILES})
target_link_libraries(OpenglES Common ${TARGET_LIB})