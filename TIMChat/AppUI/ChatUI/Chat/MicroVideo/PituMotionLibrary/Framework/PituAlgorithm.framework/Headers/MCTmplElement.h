//
//  MCTmplElement.h
//  FilterMaster
//
//  Created by billwang on 16/2/20.
//  Copyright © 2016年 Pitu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import <AVFoundation/AVFoundation.h>

#define MC_STANDARD_WIDTH 720.f
#define MC_STANDARD_HEIGHT 960.f

typedef enum {
    MCTmplElementUnknown,
    MCTmplElementStatic,
    MCTmplElementDynamic,
} MCTmplElementType;

typedef enum {
    MCTmplElementFrameSequence, // 按时间序列播放序列帧
    MCTmplElementFrameFeature, // 按表情状态值播放序列帧
} MCTmplElementFrameType;

typedef enum {
    MCTmplElementTriggerUnknown,
    MCTmplElementTriggerAlways,
    MCTmplElementTriggerFaceDetected,
    MCTmplElementTriggerOpenMouth,
    MCTmplElementTriggerBlinkEyebrow,
    MCTmplElementTriggerBlinkEye,
    MCTmplElementTriggerShakeHead,
    MCTmplElementTriggerKiss,
    MCTmplElementTriggerBlinkLeftEye,
    MCTmplElementTriggerBlinkRightEye,
    MCTmplElementTriggerNod,
    MCTmplElementTriggerFaceActionReverse = 100,
    MCTmplElementTriggerFaceDetectedNotOpenMouth = 103,
    MCTmplElementTriggerFaceDetectedNotBlinkEyebrow = 104,
    MCTmplElementTriggerFaceDetectedNotBlinkEye = 105,
    MCTmplElementTriggerFaceDetectedNotShakeHead = 106,
    MCTmplElementTriggerFaceDetectedNotKiss = 107,
    MCTmplElementTriggerFaceDetectedNotBlinkLeftEye = 108,
    MCTmplElementTriggerFaceDetectedNotBlinkRightEye = 109,
    MCTmplElementTriggerFaceDetectedNotNod = 110,
} MCTmplElementTriggerType;

typedef enum {
    MCTmplElementFeatureNone,
    MCTmplElementFeatureAllEyesOpen,
    MCTmplElementFeatureMouthOpen,
    MCTmplElementFeatureAnyEyeOpen,
    MCTmplElementFeatureLeftEyeOpen,
    MCTmplElementFeatureRightEyeOpen,
} MCTmplElementFeatureType;

typedef enum {
    MCFaceNotFound,
    MCFaceDetected,
    MCFaceOpenMouse,
    MCFaceBlinkEyebrow,
    MCFaceBlinkEye,
    MCFaceShakeHead,
    MCFaceKiss,
    MCFaceBlinkLeftEye,
    MCFaceBlinkRightEye,
    MCFaceNod,
} MCFaceStat;

typedef enum {
    MCFaceStatusCloseLeftEye,
    MCFaceStatusOpenLeftEye_20,
    MCFaceStatusOpenLeftEye_40,
    MCFaceStatusOpenLeftEye_60,
    MCFaceStatusOpenLeftEye_80,
    MCFaceStatusOpenLeftEye_100,
} MCFaceStatus_LeftEye;
typedef enum {
    MCFaceStatusCloseRightEye,
    MCFaceStatusOpenRightEye_20,
    MCFaceStatusOpenRightEye_40,
    MCFaceStatusOpenRightEye_60,
    MCFaceStatusOpenRightEye_80,
    MCFaceStatusOpenRightEye_100,
} MCFaceStatus_RightEye;

typedef enum {
    MCFaceStatusCloseMouth,
    MCFaceStatusOpenMouth_20,
    MCFaceStatusOpenMouth_40,
    MCFaceStatusOpenMouth_60,
    MCFaceStatusOpenMouth_80,
    MCFaceStatusOpenMouth_100,
} MCFaceStatus_Mouth;

@class AnalyzingFaceManager;
@interface MCTmplElement : NSObject

@property (nonatomic, copy) NSString *elementID;
@property (nonatomic, copy) NSString *elementName;
@property (nonatomic, assign) MCTmplElementType type;
@property (nonatomic, assign) MCTmplElementTriggerType triggerType;
@property (nonatomic, assign) BOOL alwaysTriggered; // 1=需要持续触发条件 0=触发条件消失后可以继续播放到playCount指定的次数为止
@property (nonatomic, assign) MCTmplElementFeatureType featureStatType;
@property (nonatomic, assign) CGPoint featureStatValueRange;
@property (nonatomic, assign) NSInteger playCount;
@property (nonatomic, assign) MCTmplElementFrameType frameType;
@property (nonatomic, assign) NSTimeInterval frameDuration;
@property (nonatomic, assign) NSInteger frames;
@property (nonatomic, assign) CGSize textureSize;
@property (nonatomic, assign) CGPoint texturePosition;
@property (nonatomic, assign) CGPoint textureAnchor;
@property (nonatomic, strong) NSArray *alignFacePoints;
@property (nonatomic, strong) NSArray *scalePivots;
@property (nonatomic, assign) CGFloat scaleWidthFactor;
@property (nonatomic, copy) NSString *audioName;
@property (nonatomic, assign) NSInteger blendMode;  //优先全局blendMode
@property (nonatomic, assign) NSInteger orderMode;  //服从全局orderMode
@property (nonatomic, assign) NSInteger personID;
@property (nonatomic, assign) CGFloat stickerRangleMin; //用于随机贴纸的随机范围
@property (nonatomic, assign) CGFloat stickerRangleMax; //用于随机贴纸的随机范围
@property (nonatomic, assign) int stickerAlphaType;

@property (nonatomic, assign) CGSize renderScale;
@property (nonatomic, copy) NSString *folderPath;
@property (atomic, strong) AVAudioPlayer *audioPlayer;
@property (atomic, strong) NSTimer *audioTimer;

@property (nonatomic, assign) NSTimeInterval beginTime;
@property (nonatomic, assign) NSInteger playedTimes;
@property (nonatomic, assign) BOOL enable3D;

- (void)preloadResource;
- (void)clearResource;
- (void)advanceTime:(NSTimeInterval)duration;
- (void)playAudio;
- (void)pauseAudioDelayed;
- (void)pauseAudio;
- (void)stopAudio;

- (BOOL)triggerStat:(MCFaceStat)faceStat;
- (BOOL)featureStat:(AnalyzingFaceManager *)faceAnalyzer;
- (GLKTextureInfo *)currentTexture;
- (GLKTextureInfo *)currentTexture:(AnalyzingFaceManager *)faceAnalyzer;
- (GLfloat *)positionVertex;
- (GLfloat *)positionVertex:(float (*)[2])facePoints withImageSize:(CGSize)imgSize;
- (GLfloat *)textureCoordinate;
- (CGPoint)textureAnchorPosition:(float (*)[2])facePoints withImageSize:(CGSize)imgSize;
- (CGFloat)textureScale:(float (*)[2])facePoints withImageSize:(CGSize)imgSize;
- (CGFloat)textureRotate:(float (*)[2])facePoints withImageSize:(CGSize)imgSize;

@end
