//
// Created by jiangshipeng on 2016/12/6.
//

#ifndef OPENGLES_CHAPTER_6_6_H
#define OPENGLES_CHAPTER_6_6_H

#include "esUtil.h"

#define VERTEX_POS_SIZE       3 // x, y and z
#define VERTEX_COLOR_SIZE     4 // r, g, b, and a

#define VERTEX_POS_INDX       0
#define VERTEX_COLOR_INDX     1

typedef struct{
    GLuint programObject;
    // VertexBufferObject Ids
    GLuint vboIds[3];
} UserData;

/**
 * draw something
 * @param esContext
 */
void Draw ( ESContext *esContext );
/**
 * 窗口关闭回调函数
 * @param esContext
 */
void Shutdown ( ESContext *esContext );

/**
 * 通过vbo
 * @param esContext
 * @param numVertices
 * @param vtxBuf
 * @param vtxStrides
 * @param numIndices
 * @param indices
 */
void drawPrimitiveWithVBOs ( ESContext *esContext,
                             GLint numVertices, GLfloat **vtxBuf,
                             GLint *vtxStrides, GLint numIndices,
                             GLushort *indices );

/**
 * 初始化配置
 * @param esContext
 */
int init(ESContext *esContext);
#endif //OPENGLES_CHAPTER_6_6_H
