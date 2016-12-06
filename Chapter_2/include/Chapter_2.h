//
// Created by jiangshipeng on 2016/12/5.
//

#ifndef OPENGLES_HELLOTRIANGLE_H
#define OPENGLES_HELLOTRIANGLE_H

#include "esUtil.h"

/**
 * 第一个三角型
 */

/**
 * 加载shader
 * @param type
 * @param shaderSrc
 * @return
 */
GLuint LoadShader(GLenum type,const char* shaderSrc);
/**
 * 初始化
 * @param esContext
 * @return
 */
int init(ESContext *esContext);
/**
 * draw something
 * @param esContext
 */
void Draw ( ESContext *esContext );

/**
 * 停止
 * @param esContext
 */
void Shutdown(ESContext *esContext);

typedef struct {
    GLuint programObject;
} UserData;

#endif //OPENGLES_HELLOTRIANGLE_H
