#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TXUGCRecordTypeDef.h"
#import "TXUGCRecordListener.h"

/**********************************************
 **************  推流端短视频录制   **************
 **********************************************/

@interface TXUGCRecord : NSObject

@property (nonatomic, weak)   id<TXVideoRecordListener>   recordDelegate;


+(TXUGCRecord*) shareInstance;


/*
 * 开始画面预览
 * 参  数：
 *       preview 预览画面的父view
 */
-(int) startCameraSimple:(TXUGCSimpleConfig*)config preview:(UIView *)preview;


/*
 * 开始画面预览
 * 参  数：
 *       preview 预览画面的父view
 */
-(int) startCameraCustom:(TXUGCCustomConfig*)config preview:(UIView *)preview;

/*
 * 结束画面预览
 */
-(void) stopCameraPreview;

/*
 * 开始录制短视频
 * 返回值：
 *       0 成功；
 *      -1 正在录制短视频；
 *      -2 videoRecorder初始化失败；
 */
-(int) startRecord;

/*
 * 结束录制短视频
 * 返回值：
 *       0 成功；
 *      -1 不存在录制任务；
 *      -2 videoRecorder未初始化；
 */
-(int) stopRecord;

#pragma mark ----Camera, Beauty, Filter----

/*
 * 切换前后摄像头
 * 参  数：
 *       isFront 是否前后摄像头
 * 返回：
 *      YES，切换成功。
 *      NO，切换失败。
 */
-(BOOL) switchCamera:(BOOL)isFront;


/* setBeautyDepth 设置美颜 和 美白 效果级别
 * 参数：
 *          beautyDepth     : 美颜级别取值范围 0 ~ 9； 0 表示关闭 1 ~ 9值越大 效果越明显。
 *          whiteningDepth  : 美白级别取值范围 0 ~ 9； 0 表示关闭 1 ~ 9值越大 效果越明显。
 */
-(void) setBeautyDepth:(float)beautyDepth WhiteningDepth:(float)whiteningDepth;

/* setFilter 设置指定素材滤镜特效
 * 参数：
 *          image     : 指定素材，即颜色查找表图片。注意：一定要用png格式！！！
 *          demo用到的滤镜查找表图片位于RTMPiOSDemo/RTMPiOSDemo/resource／FilterResource.bundle中
 */
-(void) setFilter:(UIImage*)filterImage;

/* setSpecialRatio 设置滤镜效果程度
 * 参数：
 *          specialValue     : 从0到1，越大滤镜效果越明显，默认取值0.5
 */
-(void) setSpecialRatio:(float)specialRatio;

/* toggleTorch, 打开闪关灯。
 * 参数
 *          enable: YES, 打开    NO, 关闭.
 * 返回：
 *          YES，打开成功。
 *          NO，打开失败。
 */
-(BOOL) toggleTorch:(BOOL)enable;

/* setEyeScaleLevel  设置大眼级别（特权版本有效，普通版本设置此参数无效）
 * 参数：
 *          eyeScaleLevel     : 大眼级别取值范围 0 ~ 9； 0 表示关闭 1 ~ 9值越大 效果越明显。
 */
-(void)setEyeScaleLevel:(float)eyeScaleLevel;

/* setFaceScaleLevel  设置瘦脸级别（特权版本有效，普通版本设置此参数无效）
 * 参数：
 *          faceScaleLevel    : 瘦脸级别取值范围 0 ~ 9； 0 表示关闭 1 ~ 9值越大 效果越明显。
 */
-(void)setFaceScaleLevel:(float)faceScaleLevel;

/**
 * 设置绿幕文件
 *
 * @param file: 绿幕文件路径。支持mp4; nil 关闭绿幕
 */
-(void)setGreenScreenFile:(NSURL *)file;

/**
 * 选择动效
 *
 */
- (void)selectMotionTmpl:(NSString *)tmplName inDir:(NSString *)tmplDir;


- (BOOL)    playBGM:(nullable NSString *)path
    withBeginNotify:(void (^)(NSInteger errCode))beginNotify
 withProgressNotify:(void (^)(NSInteger progressMS, NSInteger durationMS))progressNotify
  andCompleteNotify:(void (^)(NSInteger errCode))completeNotify;

- (BOOL)stopBGM;

- (BOOL)setMicVolume:(float)volume;

- (BOOL)setBGMVolume:(float)volume;
@end
