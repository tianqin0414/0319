//
//  AnalyzingFaceManager.h
//  ttpic
//
//  Created by ricocheng on 2/29/16.
//  Copyright © 2016 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FilterEngine/ImageDefine.h>
#import "MCTmplElement.h"

@interface AnalyzingFaceModel : NSOrderedSet

@property (nonatomic, assign) CGFloat leftEye;
@property (nonatomic, assign) CGFloat rightEye;
@property (nonatomic, assign) CGFloat mouth;
@property (nonatomic, assign) CGFloat kiss;
@end

@class FaceDetectorFeature;
@interface AnalyzingFaceManager : NSObject

@property (nonatomic, assign) CGPoint facePosition; //人脸位置百分比
@property (nonatomic, assign) NSInteger faceIndex;  //人脸位置下标
@property (nonatomic, assign) CGFloat charmValue;   //用于随机人脸
@property (nonatomic, strong) AnalyzingFaceModel *analyzingFaceModel;

+ (void)reMarkFeature:(float (*)[2])outline;
+ (void)reMarkFeatureVersion2:(float (*)[2])outline;

- (void)inputFaceFeature:(FaceDetectorFeature *)feature;
- (AnalyzingFaceModel *)getFaceStatus:(FaceDetectorFeature *)feature;
- (void)clearFaceFeatures;
- (void)getFeaturePoints:(float [FACE_FEATURE_NUM+7][2])points;

//4.0版本新增了左右脸颊，左右鼻孔， 4.3版本新增嘴中间位置
- (void)getFeaturePointsVersion2:(float [FACE_FEATURE_NUM+7+5][2])points;

- (CGSize)getFeatureImageSize;
- (BOOL)detectFaceStat:(MCFaceStat)statType;
- (void) getLastModelPitch: (CGFloat *) pitch yaw:(CGFloat *) yaw roll:(CGFloat *) roll;

@end
