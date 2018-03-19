//
//  MCTmplItem.h
//  FilterMaster
//
//  Created by billwang on 16/2/20.
//  Copyright © 2016年 Pitu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCTmplElement.h"

#define ENABLE_FACEOFF 1
#define ENABLE_FACEMESH 1
#define ENABLE_FACESWAP 1

typedef enum {
    MCTmplShaderCommon = 0, //0
    MCTmplShaderCustomPreprocess = 1,
    MCTmplShaderCustomPostprocess = 2,
    MCTmplShaderSnakeFace = 3,
    MCTmplShaderCVS = 4,    //common vertex shader
    MCTmplShaderFaceOff = 5,//5:换脸
    MCTmplShaderMesh = 6, //6:变形
    MCTmplShaderFaceSwap = 7, //7：同屏换脸，复制脸 （版本4.3）
    MCTmplShaderFaceOffMesh = 8,    //8: 换脸+形变 （版本4.2）
    MCTmplShaderNotUse = 9, // 无用类型，由于某些历史原因，9被跳过
    MCTmplShaderFaceSwapAndroid = 10, // 同屏换脸安卓配成了10，这里做个兼容 （版本4.3）
    MCTmplShaderFaceCopyAndroid = 11, // 同屏复制脸安卓配成了11，这里做个兼容
    MCTmplShaderCount,      //总数
} MCTmplShaderType;

typedef enum {
    MCTmplFilterEffectNone,
    MCTmplFilterEffectLookuptable,
    MCTmplFilterEffectCustom,
    MCTmplFilterEffectTypeCount,
} MCTmplFilterEffectType;

typedef enum {
    MCTmplFilterEffectNoprocess,
    MCTmplFilterEffectPreprocess,
    MCTmplFilterEffectPostprocess,
    MCTmplFilterEffectOrderCount,
} MCTmplFilterEffectOrder;

typedef enum {
    MCFaceOffErrorNone = -1,
    MCFaceOffNormal = 0, // 素材换脸
    MCFaceOffFromAlbum = 1, // 从相册中选取图片进行换脸
}MCFaceOffType;

typedef enum {
    MCFaceSwapNormal, //同屏换脸
    MCFaceSwapCopyFace, //同屏复制脸
}MCFaceSwapType;


typedef enum {
    MCTmplAudioEnabled = 0,
    MCTmplAudioDisabled = 1 << 0, // user pressed disabled audio button
    MCTmplAudioInactive = 1 << 1, // app return to background
} MCTmplAudioStat;

@interface MetaDistortion: NSObject
@property(assign, nonatomic) float strength;
@property(assign, nonatomic) float radius;
@property(assign, nonatomic) int direction;
@property(assign, nonatomic) int distortion;
@property(assign, nonatomic) int position;
@end

@interface MetaFaceDeform : NSObject

@property (nonatomic, assign) int position, pos1, pos2;
@property (nonatomic, assign) float ratio1, ratio2;
@property (nonatomic, assign) int dx, dy;

@end

@interface MCDoodlePattern : NSObject

@property (nonatomic, assign) CGSize imageSize;
@property (nonatomic, assign) NSInteger count;
@property (nonatomic, copy) NSString *folderPath;
- (GLKTextureInfo *)currentTexture;
- (void)preloadResource;
@end


@interface MCTmplItem : NSObject
@property (nonatomic, copy) NSString *itemName;
@property (nonatomic, assign) NSInteger minAppVersion;
@property (nonatomic, assign) NSInteger maxFaceCount;
@property (nonatomic, assign) MCTmplShaderType shaderType;
@property (nonatomic, copy) NSString *filterId;
@property (nonatomic, assign) MCTmplFilterEffectType filterEffectType;
@property (nonatomic, assign) MCTmplFilterEffectOrder filterEffectOrder;
@property (nonatomic, copy) NSString *filterEffectLookupFilename;
@property (nonatomic, copy) NSString *folderPath;
@property (nonatomic, assign) MCTmplElementTriggerType actionTriggerType;
@property (nonatomic, strong) NSArray<NSString *> *resourceList;
@property (nonatomic, strong) NSArray<MCTmplElement *> *elements;
@property (nonatomic, assign) NSTimeInterval beginTime;
@property (nonatomic, assign) NSInteger faceActionTipsCount;
@property (nonatomic, assign) NSInteger faceDetectSkipCount;
@property (nonatomic, assign) BOOL hasAudio;
@property (atomic, assign) NSInteger audioStat;
@property (nonatomic, assign) NSInteger blendMode;
@property (nonatomic, assign) NSInteger orderMode;       //贴纸与形变的顺序, 1代表先形变再贴纸（默认，旧有逻辑），2代表先贴纸再形变
@property (nonatomic, assign) int stickerAlphaType;      //alpha类别
@property (nonatomic, strong) MCDoodlePattern *pattern;


#if ENABLE_FACEOFF
@property (nonatomic, copy) NSString * faceExchangeImage;
@property (nonatomic, copy) NSString * imageFacePointsFileName;
@property (nonatomic, copy) NSString * faceExchageFeature;
@property (nonatomic, assign) float blendAlpha;
@property (nonatomic, assign) int featureType;
@property (nonatomic, assign) int grayScale;
@property (nonatomic, strong) NSArray * facePoints;
@property (nonatomic, assign) MCFaceOffType faceOffType;
#endif

 
#if ENABLE_FACEMESH
@property (nonatomic, strong) NSArray <MetaDistortion *> * meshDistortionItems; //用扩大、缩小的方式形变
@property (nonatomic, strong) NSArray <MetaFaceDeform *> * meshFaceDeformItems; //用贴三角的方式形变
@property (nonatomic, strong) NSArray <NSNumber *> * meshFaceDeformTriangles;    //贴三角方式形变的三角形数组
#endif

#if ENABLE_FACESWAP
@property (nonatomic, assign) MCFaceSwapType faceswapType;
#endif



+ (MCTmplItem *)parseTemplate:(NSString *)tmplName inDirectory:(NSString *)folderPath withJsonDic:(NSDictionary *)tmplObj;
+ (BOOL)checkTemplateIfHasAudio:(NSDictionary *)tmplObj;

- (void)updateRenderSize:(CGSize)renderSize;

- (NSString *)vertexShaderPath;
- (NSString *)fragmentShaderPath;
- (NSString *)filterEffectVertexPath;
- (NSString *)filterEffectFragmentPath;

- (void)preloadResource;
- (void)clearResource;
- (GLKTextureInfo *)textureWithName:(NSString *)texName;
- (void)advanceTime;

- (void)prepareForFilterUse;
- (void)pauseWhenFilterPause;
- (void)didFinishUse;

- (void)deviceDidBecomeActive;
- (void)deviceWillResignActive;

@end
