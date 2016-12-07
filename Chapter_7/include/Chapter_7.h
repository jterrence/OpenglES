//
// Created by jiangshipeng on 2016/12/7.
//

#ifndef OPENGLES_CHAPTER_7_H_H
#define OPENGLES_CHAPTER_7_H_H
#include "esUtil.h"

#define NUM_INSTANCES   100
#define POSITION_LOC    0
#define COLOR_LOC       1
#define MVP_LOC         2

typedef struct {
    // Handle to a program object
    GLuint programObject;
    // VBOs
    GLuint positionVBO;
    GLuint colorVBO;
    GLuint mvpVBO;
    GLuint indicesIBO;
    // Number of indices
    int       numIndices;
    // Rotation angle
    GLfloat   angle[NUM_INSTANCES];

} UserData;

/**
 * 初始化shader和程序
 * @param esContext
 * @return
 */
int init ( ESContext *esContext );
/**
 * 关闭窗口回调
 * @param esContext
 */
void Shutdown ( ESContext *esContext );
/**
 * 渲染回调函数
 * @param esContext
 */
void draw ( ESContext *esContext );
/**
 * 更新状态
 * @param esContext
 * @param deltaTime
 */
void update (ESContext *esContext, float deltaTime );

#endif //OPENGLES_CHAPTER_7_H_H
