//
//  YoutuDetector.h
//  FilterEngine
//
//  Created by  patyang on 14-3-4.
//  Copyright (c) 2014年 Microrapid. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FilterEngine/FilterEngine.h>
#import "PituAlgorithm.h"

typedef enum {
    YoutuTrackingHigh, // 持续追踪，默认值
    YoutuTrackingLow, // 隔帧追踪
} YoutuTrackingLevel;

@interface YoutuDetector : FaceDetector

@property (nonatomic, assign) BOOL trackingEnabled;
@property (nonatomic, assign) YoutuTrackingLevel trackingLevel;
@property (nonatomic, assign) NSInteger maxTrackingFace;
@property (nonatomic, assign) NSInteger maxSkipTrackFailedCount;
@property (nonatomic, assign) NSTimeInterval detectInterval;
@property (nonatomic, assign) BOOL forceDetect;
@property (nonatomic, assign) BOOL crashWhenFaceAlignmentFailed;

- (void)trackVideoFaceFeature:(Image *)image withFinishBlock:(void (^)(void))finishBlock;
- (void)detectVideoFaceFeature:(Image *)image;

@end

@interface YoutuDetectorManager : NSObject

+ (NSString *)versions;
+ (instancetype)sharedManager;
- (void)setupDataModels;
- (void)releaseDataModel;

@end
