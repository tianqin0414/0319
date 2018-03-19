//
//  TXVideoCustomProcessDelegate.h
//  TXRTMPSDK
//
//  Created by annidyfeng on 2017/3/20.
//
//

#import <Foundation/Foundation.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

@protocol TXVideoCustomProcessDelegate <NSObject>
@optional
#pragma mark - Pusher
/**
 * 在OpenGL线程中回调，在这里可以进行采集图像的二次处理
 * @param textureId  纹理ID
 * @param width      纹理的宽度
 * @param height     纹理的高度
 * @return           返回给SDK的纹理
 * 说明：SDK回调出来的纹理类型是GL_TEXTURE_2D，接口返回给SDK的纹理类型也必须是GL_TEXTURE_2D; 该回调在SDK美颜之后. 纹理格式为GL_RGBA
 */
- (GLuint)onPreProcessTexture:(GLuint)texture width:(CGFloat)width height:(CGFloat)height;

/**
 * 在OpenGL线程中回调，可以在这里释放创建的OpenGL资源
 */
- (void)onTextureDestoryed;

#pragma mark - Player
/**
 * 视频渲染对象回调
 * @prarm pixelBuffer   渲染图像
 * @return              返回YES则SDK不再显示；返回NO则SDK渲染模块继续渲染
 *  说明：渲染图像的数据类型为config中设置的renderPixelFormatType
 */
- (BOOL)onPlayerPixelBuffer:(CVPixelBufferRef)pixelBuffer;
@end
