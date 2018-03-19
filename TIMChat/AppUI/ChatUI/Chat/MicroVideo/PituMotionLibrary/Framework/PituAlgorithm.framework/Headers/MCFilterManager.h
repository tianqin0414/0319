//
//  MCFilterManager.h
//  PituMotionDemo
//
//  Created by billwang on 16/5/30.
//  Copyright © 2016年 Pitu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GPUImageCropFilter.h"
#import "YouTuDetector.h"
#import "MotionCamera.h"

#define kMC_FILTER_TYPE @"filterType"
#define kMC_FILTER_PARAMS @"filterParams"

typedef enum {
    MCFilterOutputRotationAuto,
    MCFilterOutputRotationPortrait,
    MCFilterOutputRotationPortraitUpsideDown,
    MCFilterOutputRotationLandscapeLeft,
    MCFilterOutputRotationLandscapeRight,
    MCFilterOutputRotationQzoneAVSDK,// 方向同MCFilterOutputRotationLandscapeLeft，但是如果设了前置摄像头翻转输出时会翻转回去
} MCFilterOutputRotationType;


@class MCFilterManager;
@protocol MCFilterManagerDelegate <NSObject>

@optional
// 录制视频的时间回调
- (void)MCFilterManager:(MCFilterManager *)manager updateRecordingTimeSeconds:(NSTimeInterval)second;
// 如果动效模板指定了某个滤镜，通过此方法通知上层；如果上层没有实现此方法或者返回NO，MCFilterManager会内部自己处理，但是注意内部自己处理的话不会更新上层ui
- (BOOL)MCFilterManager:(MCFilterManager *)manager motionTmplSelectFilter:(NSString *)filterID;

@end


@interface MCFilterManager : NSObject

@property (nonatomic, weak) id<MCFilterDelegate, MCDataOutputDelegate, MCFilterManagerDelegate> delegate;

// 动效滤镜必要资源的目录，默认为@"Resource/data"
@property (nonatomic, copy) NSString *motionFilterDataFolder;

// 滤镜列表配置，主要用于模板指定滤镜时根据字符串id找到对应的滤镜，内置了默认列表，也可外部赋值替换
/*
@{
 @"cameftOrigin":@{kMC_FILTER_TYPE:@(MIC_LENS)},
 @"cameftRomantic":@{kMC_FILTER_TYPE:@(MIC_PTU_FBBS), kMC_FILTER_PARAMS:@{@"style":@"LANGMAN"}},
 @"cameftShengdai":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_LIGHTWHITE)},
 @"cameftMoscow":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_MAPLERED)},
 @"cameftYinghong":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_LIGHTRED)},
 @"cameftTianmei":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_TIANMEI)},
 @"cameftSeoul":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_RICHRED)},
 @"cameftMediterranean":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_RICHBLUE)},
 @"cameftNuanyang":@{kMC_FILTER_TYPE:@(MIC_PTU_FBBS), kMC_FILTER_PARAMS:@{@"style":@"NUANYANG"}},
 @"cameftFenbi":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_OKINAWA)},
 @"cameftTianbohe":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_LIGHTGREEN)},
 @"cameftLinjia":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_NEXTDOOR)},
 @"cameftFennen":@{kMC_FILTER_TYPE:@(MIC_PTU_FEN2_REAL)},
 @"cameftSapporo":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_SAPPORO)},
 @"cameftShowa":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_YOUNG)},
 @"cameftTokyo":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_TOKYO)},
 @"cameftMolv":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_MILKGREEN)},
 @"cameftFlorence":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_RICHYELLOW)},
 @"cameftOkinawa":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_OCEAN)},
 @"cameftNara":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_MEDSEA)},
 @"cameftJiaocha":@{kMC_FILTER_TYPE:@(MIC_PTU_ZIPAI_COFFEE)},
}
*/
@property (nonatomic, strong) NSDictionary *filterList;

// 可自由串入的自定义滤镜，主要用于调试
@property (nonatomic, strong) GPUImageFilter *customFilter;

// 预览视图
@property (nonatomic, strong) NSObject<GPUImageInput> *previewFilter;

// 期望的视频和拍照输出尺寸
@property (nonatomic, assign) CGSize preferedVideoSize; // 默认480x640
@property (nonatomic, assign) CGSize preferedPhotoSize; // 默认960x1280

// 期望的推流回吐格式，默认为MCDataOutputFormatBGRA（支持VideoToolBox硬编码）
@property (nonatomic, assign) MCDataOutputFormatType outputFormat;

// 期望的输出图像方向，默认为MCFilterOutputRotationAuto根据设备方向自动旋转
@property (nonatomic, assign) MCFilterOutputRotationType outputRotation;

// 视频录制时的比特率, 默认为512KB/s
@property (nonatomic, assign) int videoBitRate;

// 是否进行镜像翻转，默认为NO，前置摄像头采样数据有镜像效果，把frontCameraMirror设为yes可以翻转回来
@property (nonatomic, assign) BOOL frontCameraMirror;

// 最后一次收到采样数据的尺寸
@property (nonatomic, readonly) CGSize sampleSize;
// 当前的预览画面尺寸
@property (nonatomic, readonly) CGSize renderSize;

// 动效模版
@property (nonatomic, strong) MCTmplItem *motionItem;
// 主动设置动效拍静音
@property (nonatomic, assign) BOOL motionMuted;
// 退后台时设置动效拍音效暂停，返回时设置恢复
@property (nonatomic, assign) BOOL motionInactive;

// 人脸检测
@property (nonatomic, strong) NSArray *faceAnalyzers;
// 五官追踪接口
@property (nonatomic, readonly) YoutuDetector *faceDetector;

// 控制台输出性能打点数据，调试专用
@property (nonatomic, assign) BOOL enableConsoleLog;

// 视频录制的文件路径
+ (NSString *)videoRecordTempPath;
// 视频保存的文件路径
+ (NSString *)videoSaveTempPath;

// 解密动效模版
+ (NSDictionary *)parseTemplateFileWithFullPath:(NSString *)xmlFileFullPath;

// 初始化并设置人脸检测图的短边尺寸（设置较小的人脸检测图尺寸可以提升性能）
- (id)initWithFaceDetectTargetMaxEdge:(CGFloat)faceMaxEdge;

// 选择动效模版
- (void)selectMotionTmpl:(NSString *)tmplName inDir:(NSString *)tmplDir;

// 设置美颜等级
- (void)setupBeautyLevel:(NSInteger)level;

// 设置效果滤镜
- (void)setupEffectFilter:(GPUImageShowcaseFilterType)filterType params:(NSDictionary *)params;

// 传入摄像头采样的原始帧数据
- (void)receiveVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (void)receiveAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer;

// 拍照
- (UIImage *)takePhoto:(CMSampleBufferRef)sampleBuffer;

// 视频录制
- (BOOL)startRecordVideo:(void(^)(void))callback;
- (void)finishRecordVideo:(void(^)(BOOL finish, NSTimeInterval totalDuration))result;
- (void)cancelRecordVideo;

// 推流回吐
- (BOOL)startOutputData;
- (void)stopOutputData:(void (^)())handler;
- (void)mediaServicesReseted:(NSNotification *)noti;

// 获取当前预览截图
- (UIImage *)currentResultImage;

@end
