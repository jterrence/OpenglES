set ( common_src Source/esShader.c 
                 Source/esShapes.c
                 Source/esTransform.c
                 Source/esUtil.c )


# Win32 Platform files
if(WIN32)
    set( common_platform_src Source/Win32/esUtil_win32.c )
    add_library( Common STATIC ${common_src} ${common_platform_src} )
    target_link_libraries( Common ${OPENGLES3_LIBRARY} ${EGL_LIBRARY} )
else()
    find_package(X11)
    find_library(M_LIB m)
    set( common_platform_src Source/LinuxX11/esUtil_X11.c ../Chapter_6/include/Chapter_6_3.h ../Chapter_6/Chapter_6_3.c ../Chapter_7/include/Chapter_7.h ../Utils/ESUtil.c ../Chapter_9/Chapter_9_cubemap/include/Chapter_9_cubemap.h ../Chapter_9/Chapter_9_cubemap/Chapter_9_cubemap.c ../Chapter_9/Chapter_9_mipMap2D/include/Chapter_9_mipMap2D.h ../Chapter_9/Chapter_9_mipMap2D/Chapter_9_mipMap2D.c ../Chapter_9/Chapter_9_texture2D/include/Chapter_9_texture2D.h ../Chapter_9/Chapter_9_texture2D/Chapter_9_texture2D.c ../Chapter_9/Chapter_9_textureWrap/include/Chapter_9_textureWrap.h ../Chapter_9/Chapter_9_textureWrap/Chapter_9_textureWrap.c)
    add_library( Common STATIC ${common_src} ${common_platform_src} )
    target_link_libraries( Common ${OPENGLES3_LIBRARY} ${EGL_LIBRARY} ${X11_LIBRARIES} ${M_LIB} )
endif()

             


