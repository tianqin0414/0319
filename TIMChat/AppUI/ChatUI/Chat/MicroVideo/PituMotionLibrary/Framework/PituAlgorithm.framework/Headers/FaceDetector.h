//
//  FaceDetector.h
//  FilterEngine
//
//  Created by  patyang on 14-3-4.
//  Copyright (c) 2014年 Microrapid. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FilterEngine/ImageDefine.h>

@class UIImage;

typedef enum {
    FaceDetector_System = 0,
    FaceDetector_FacePP,
    FaceDetector_Youtu,
    FaceDetector_OpenCV
} FaceDetectorType;

typedef enum {
    FaceDetectorAccuracyLow = 0,
    FaceDetectorAccuracyHigh
} FaceDetectorAccuracy;

@interface FaceDetectorFeature : NSObject

@property (nonatomic, assign) CGSize imageSize;
@property (nonatomic, assign) CGRect bounds;
@property (nonatomic, assign) CGRect leBounds;
@property (nonatomic, assign) CGRect reBounds;
@property (nonatomic, assign) CGRect mouthBounds;
@property (nonatomic, readonly) BOOL hasOutline;
@property (nonatomic, assign) CGFloat pitch;
@property (nonatomic, assign) CGFloat yaw;
@property (nonatomic, assign) CGFloat roll;

- (void)setFeatures:(int [FACE_FEATURE_NUM][2])points;
- (void)getFeatures:(int [FACE_FEATURE_NUM][2])points;
- (void)setF_Features:(float [FACE_FEATURE_NUM][2])points;
- (void)getF_Features:(float [FACE_FEATURE_NUM][2])points;
- (void)setScaleX:(CGFloat)scaleX scaleY:(CGFloat)scaleY;
- (void)updateImageSize:(CGSize)imageSize;
- (BOOL)correct;
- (FaceDetectorFeature *)scaleFeatureSize:(CGSize)size;
- (FaceDetectorFeature *)rotateFeature:(CGFloat)radian;

+ (CGRect)calcPointsBounds:(int [][2])points count:(NSInteger)count;

@end

@interface FaceDetector : NSObject
{
    NSMutableArray *faces;
}

@property (nonatomic, assign) FaceDetectorAccuracy accuracy;
@property (nonatomic, assign) BOOL faceBoundsOnly;
@property (nonatomic, assign) float targetMaxEdge;

+ (FaceDetector *)createDetector:(FaceDetectorType)type;
+ (BOOL)isDetectorTypeAvailable:(FaceDetectorType)type;

+ (void)transYT2Facepp88:(float *)ytFeatures outline:(int [][2]) faceOutline;
+ (void)transYT2Facepp90:(float *)ytFeatures outline:(int [][2]) faceOutline;
+ (void)transYT2Facepp88V2:(float *)ytFeatures outline:(float [][2]) faceOutline;
+ (void)transYT2Facepp90V2:(float *)ytFeatures outline:(float [][2]) faceOutline;
+ (void)registerFacedect:(NSString *)key class:(Class)aClass;;


- (void)setYoutuParam:(struct FaceDetectParam *)param;
- (void)detectFaceFeature:(UIImage *)image;
- (void)detectFaceFeature:(UIImage *)image withFaceRect:(CGRect)rect;
- (void)detectFaceFeature:(UIImage *)image withLeftEye:(CGPoint)left rightEye:(CGPoint)right;
- (UIImage *)formatInputImage:(UIImage *)image;
- (NSInteger)faceCount;
- (BOOL)isFemaleFaceAtIndex:(NSInteger)index;
- (CGPoint)leftEyeCenterAtIndex:(NSInteger)index;
- (CGPoint)rightEyeCenterAtIndex:(NSInteger)index;
- (struct _Rect)faceRectAtIndex:(NSInteger)index;
- (struct _Rect)leftEyeRectAtIndex:(NSInteger)index;
- (struct _Rect)rightEyeRectAtIndex:(NSInteger)index;
- (struct _Rect)mouthRectAtIndex:(NSInteger)index;
- (void)getFeaturePoints:(int [FACE_FEATURE_NUM][2])points atIndex:(NSInteger)index;
- (FaceDetectorFeature *)featureAtIndex:(NSInteger)index;

- (BOOL)correctFaceRect:(struct _Rect *)faceRect leRect:(struct _Rect *)leRect reRect:(struct _Rect *)reRect mouthRect:(struct _Rect *)mouthRect width:(int)width height:(int)height;

- (void)removeAllFaces;

@end