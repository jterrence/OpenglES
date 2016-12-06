//
// Created by jiangshipeng on 2016/12/6.
//
#include <Chapter_6_3.h>

int init (ESContext *esContext){
    UserData *userData = esContext->userData;
    const char vShaderStr[] =
            "#version 300 es                            \n"
                    "layout(location = 0) in vec4 a_position;   \n"
                    "layout(location = 1) in vec4 a_color;      \n"
                    "out vec4 v_color;                          \n"
                    "void main()                                \n"
                    "{                                          \n"
                    "    v_color = a_color;                     \n"
                    "    gl_Position = a_position;              \n"
                    "}";


    const char fShaderStr[] =
            "#version 300 es            \n"
             "precision mediump float;   \n"
             "in vec4 v_color;           \n"
             "out vec4 o_fragColor;      \n"
             "void main()                \n"
              "{                          \n"
              "    o_fragColor = v_color; \n"
              "}" ;

    GLuint programObject;
    // Create the program object
    programObject = esLoadProgram (vShaderStr, fShaderStr );

    if ( programObject == 0 ) {
        return GL_FALSE;
    }

    // Store the program object
    userData->programObject = programObject;

    //清除面板颜色
    glClearColor ( 1.0f, 1.0f, 1.0f, 0.0f );

    return GL_TRUE;

}

void Draw ( ESContext *esContext){
    UserData *userData = esContext->userData;
    GLfloat color[4] = { 0.0f, 0.0f, 1.0f, 0.0f };
    // 3 vertices, with (x,y,z) per-vertex
    GLfloat vertexPos[3 * 3] =
            {
                    0.0f,  0.5f, 0.0f, // v0
                    -0.5f, -0.5f, 0.0f, // v1
                    0.5f, -0.5f, 0.0f  // v2
            };
    //设置平截头体
    glViewport ( 0, 0, esContext->width, esContext->height );

    //清除颜色缓冲区
    glClear ( GL_COLOR_BUFFER_BIT );
    //使用程序项目
    glUseProgram ( userData->programObject );
    glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, vertexPos );
    glEnableVertexAttribArray ( 0 );
    glVertexAttrib4fv ( 1, color );
    glDrawArrays ( GL_TRIANGLES, 0, 3 );
    glDisableVertexAttribArray (1);
}

void Shutdown ( ESContext *esContext){
    UserData *userData = esContext->userData;
    glDeleteProgram ( userData->programObject );
}

int esMain (ESContext *esContext ){
    esContext->userData = malloc ( sizeof ( UserData ) );
    //创建窗口
    esCreateWindow ( esContext, "Example 6-3", 320, 240, ES_WINDOW_RGB );
    if ( !init ( esContext ) ) {
        return GL_FALSE;
    }
    //注册关闭窗口回调函数
    esRegisterShutdownFunc ( esContext, Shutdown );
    //注册图片装配完成以后回调
    esRegisterDrawFunc ( esContext, Draw );
    return GL_TRUE;
}