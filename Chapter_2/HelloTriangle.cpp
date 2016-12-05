//
// Created by jiangshipeng on 2016/12/5.
//
#include <stdlib.h>
#include <malloc.h>
#include <HelloTriangle.h>

HelloTriangle::HelloTriangle() {

}

HelloTriangle::~HelloTriangle() {

}

GLuint HelloTriangle::LoadShader(GLenum type,const char* shaderSrc) {
    GLuint shader;
    GLint  compiled;

    //创建shader对象
    shader = glCreateShader(type);

    if(shader == 0){
        return 0;
    }

    //加载shader资源
    glShaderSource(shader,1,&shaderSrc,NULL);

    //编译shader
    glCompileShader(shader);

    //检查shader编译状态
    glGetShaderiv(shader,GL_COMPILE_STATUS,&compiled);

    if(!compiled){
        GLint infoLen = 0;
        glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
        if(infoLen > 1){
            char *infoLog = (char *) malloc (sizeof ( char ) * infoLen );
            glGetShaderInfoLog(shader,infoLen,NULL,infoLog);
            esLogMessage("Error compiling shader:\n%s\n",infoLog);
            free(infoLog);
        }

        glDeleteShader ( shader );
        return 0;
    }
    return shader;
}

int HelloTriangle::init(ESContext *esContext) {
    UserData *userData = (UserData *) esContext->userData;

    //顶点着色器
    char vShaderStr[]  =
            "#version 300 es                                \n"
            "layout(location = 0) int vec4 vPosition;       \n"
            "void main()                                    \n"
            "{                                              \n"
            "   gl_Position = vPosition;                    \n"
            "}                                              \n";
    //片元着色器
    char fShaderStr[]  =
            "#version 300 es                                \n"
            "precision mediump float;                       \n"
            "out vec4 fragColor;                            \n"
            "void main()                                    \n"
            "{                                              \n"
            "   fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );    \n"
            "}                                              \n";

    GLuint vertexShader;
    GLuint fragmentShader;

    GLuint programObject;
    GLint linked;

    //加载shader
    vertexShader   = LoadShader ( GL_VERTEX_SHADER, vShaderStr );
    fragmentShader = LoadShader ( GL_FRAGMENT_SHADER, fShaderStr );

    //创建项目
    programObject  = glCreateProgram();

    if(programObject == 0){
        return 0;
    }

    //关联顶点着色器
    glAttachShader(programObject,vertexShader);
    //关联片元着色器
    glAttachShader(programObject,fragmentShader);

    //链接项目
    glLinkProgram(programObject);

    //查询链接状态
    glGetProgramiv(programObject,GL_LINK_STATUS,&linked);

    if ( !linked ) {
        GLint infoLen = 0;
        glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );

        if ( infoLen > 1 ) {
            char *infoLog = (char *)malloc ( sizeof ( char ) * infoLen );
            glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );
            esLogMessage ( "Error linking program:\n%s\n", infoLog );
            free ( infoLog );
        }

        glDeleteProgram ( programObject );
        return FALSE;
    }

    userData->programObject = programObject;

    //清除颜色缓冲区
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    return TRUE;
}

void HelloTriangle::Draw ( ESContext *esContext ){
    UserData *userData = (UserData *)esContext->userData;
    GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f,
                             -0.5f, -0.5f, 0.0f,
                             0.5f, -0.5f, 0.0f
    };

    //设置平截头体
    glViewport(0,0,esContext->width,esContext->height);

    //清除颜色缓冲区
    glClear ( GL_COLOR_BUFFER_BIT );

    // 使用项目
    glUseProgram ( userData->programObject );

    // 加载顶点数据
    // 每个顶点着色器中的属性都有一个唯一的无符号整数标识的位置
    // 调用glVertexAttribPointer把数据装载到位置0
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,vVertices);

    //启动顶点属性
    glEnableVertexAttribArray(0);

    //开始画三角形
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

void HelloTriangle::Shutdown(ESContext *esContext){
    UserData *userData = (UserData *)esContext->userData;
    glDeleteProgram ( userData->programObject );
}

void HelloTriangle::render() {

}