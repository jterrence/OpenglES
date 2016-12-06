//
// Created by jiangshipeng on 2016/12/6.
//

/**
 * 第六章第三小节
 */
#ifndef OPENGLES_CHAPTER_6_3_H
#define OPENGLES_CHAPTER_6_3_H

#include "esUtil.h"

typedef struct{
   GLuint programObject;
} UserData;
/**
 * 初始化
 * @param esContext
 * @return
 */
int init (ESContext *esContext);

/**
 * draw something
 * @param esContext
 */
void Draw ( ESContext *esContext);

/**
 * 停止
 * @param esContext
 */
void Shutdown ( ESContext *esContext );

#endif //OPENGLES_CHAPTER_6_3_H

