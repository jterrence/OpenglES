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
#添加第六章三节头文件
include_directories(${CMAKE_SOURCE_DIR}/Chapter_6/Chapter_6_3/include)
#添加第六章六节头文件
include_directories(${CMAKE_SOURCE_DIR}/Chapter_6/Chapter_6_6/include)
#包含第七章头文件
include_directories(${CMAKE_SOURCE_DIR}/Chapter_7/include)

include_directories(${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_cubemap/include)
include_directories(${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_mipMap2D/include)
include_directories(${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_texture2D/include)
include_directories(${CMAKE_SOURCE_DIR}/Chapter_9/Chapter_9_textureWrap/include)


#添加子目录后,会调用子目录下面的CMakeLists.txt文件
add_subdirectory(Common)
#设置链接库，链接库文件一定要按此顺序，否则会出现链接不成功
set(TARGET_LIB
        Common
        ${CMAKE_SOURCE_DIR}/Library/libGLESv2.lib
        ${CMAKE_SOURCE_DIR}/Library/libEGL.lib
        )

#添加第二章节目录
add_subdirectory(Chapter_2)
#添加第六章三节目录
add_subdirectory(Chapter_6/Chapter_6_3)
#添加第六章六节目录
add_subdirectory(Chapter_6/Chapter_6_6)
#添加第七章目录
add_subdirectory(Chapter_7)
#添加第九章目录
add_subdirectory(Chapter_9/Chapter_9_mipMap2D)
add_subdirectory(Chapter_9/Chapter_9_cubemap)
add_subdirectory(Chapter_9/Chapter_9_texture2D)
add_subdirectory(Chapter_9/Chapter_9_textureWrap)

add_subdirectory(Chapter_14/Noise3D)
