//
// Created by jiangshipeng on 2016/12/5.
//

#ifndef OPENGLES_HELLOTRIANGLE_H
#define OPENGLES_HELLOTRIANGLE_H

#include "esUtil.h"

/**
 * 第一个三角型
 */
class HelloTriangle {
public:
    HelloTriangle();
    ~HelloTriangle();
    GLuint LoadShader(GLenum type,const char* shaderSrc);
    int init(ESContext *esContext);
    void Draw ( ESContext *esContext );
    void Shutdown(ESContext *esContext);
    void render();
};


typedef struct {
    GLuint programObject;
} UserData;

#endif //OPENGLES_HELLOTRIANGLE_H
