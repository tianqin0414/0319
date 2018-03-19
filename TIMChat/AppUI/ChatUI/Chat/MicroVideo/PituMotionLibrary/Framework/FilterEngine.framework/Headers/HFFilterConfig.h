//
//  HFGLConfig.h
//  FilterEngine
//
//  Created by Patrick Yang on 15/6/12.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#ifndef FilterEngine_HFFilterConfig_h
#define FilterEngine_HFFilterConfig_h

#ifdef __cplusplus
#define HF_EXTERN extern "C"
#else
#define HF_EXTERN extern
#endif

#if defined ANDROID
#include <GLES2/gl2.h>
#else
#include <OpenGLES/gltypes.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#endif

/*******************   Shader   *********************/
//#define GLSL_DEBUG

#define HFSTRINGIZE(x) #x
#define HFSHADER_STRING(x) HFSTRINGIZE(x)
#define HFTEXTURE_STEP_HOR HFSTRINGIZE(horStep)
#define HFTEXTURE_STEP_VER HFSTRINGIZE(verStep)

#if defined ANDROID
#define SHADER_DES_DEFINE(x, shader) unsigned char x[] = HFSHADER_STRING(shader)
#else
#define SHADER_DES_DEFINE(x, shader) NSString *const x = @ HFSHADER_STRING(shader)
#endif

#if _MSC_VER
#define DLL_EXPORT __declspec (dllexport)
#define TEST_DEBUG 1
#elif __GNUC__
#define TEST_DEBUG 0
#define DLL_EXPORT __attribute__ ((visibility ("default")))
#endif

/*******************   Texutre   *********************/
typedef struct HFGLTextureOptions {
    GLenum minFilter;
    GLenum magFilter;
    GLenum wrapS;
    GLenum wrapT;
    GLenum glFormat;
    GLenum iosFormat;
    GLenum type;
} HFGLTextureOptions;


/*******************   Filter   *********************/
#define HFGLFILTER_TEXTURE_NUM 4

typedef enum {
    HFFlipModeNone = 0,
    HFFlipModeHorizontal,
    HFFlipModeVertical,
    HFFlipModeHorizontalVertical,
} HFFlipMode;


#endif
