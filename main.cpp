//
// Created by jiangshipeng on 2016/12/5.
//

#include <esUtil.h>
#include <HelloTriangle.h>
#include <malloc.h>

using namespace std;



int esMain (ESContext *esContext ){

    esContext->userData = malloc ( sizeof ( UserData ) );
    esCreateWindow ( esContext, "Hello Triangle", 320, 240, ES_WINDOW_RGB );

    HelloTriangle triangle;

    if ( !triangle.init( esContext ) ){
        return GL_FALSE;
    }

//    esRegisterShutdownFunc ( esContext,&HelloTriangle::Shutdown);
//    esRegisterDrawFunc ( esContext, Draw );
    return GL_TRUE;
}
