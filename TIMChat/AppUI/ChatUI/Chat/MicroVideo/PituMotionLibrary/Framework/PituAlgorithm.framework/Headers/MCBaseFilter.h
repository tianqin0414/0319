//
//  MCBaseFilter.h
//  ttpic
//
//  Created by billwang on 16/3/8.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import "GPUImageFilter.h"
#import "MCTmplItem.h"

#define MOTION_CAMERA_SHADER_ENCRYPT 1

@protocol MCFilterDelegate <NSObject>

@optional
- (void)MCFilterNeedShowTips:(NSString *)type text:(NSString *)tips withDuration:(NSTimeInterval)duration;
- (void)MCFilterNeedHideTips:(NSString *)type;
- (void)MCFilterNeedUpdateFaceSwapGuideStauteWithTmplItem: (MCTmplItem *) tmplItem faceCount: (NSInteger) faceCount withDuration:(NSTimeInterval)duration;
@end



@class AnalyzingFaceManager;
@interface MCBaseFilter : GPUImageFilter

@property (atomic, strong) MCTmplItem *tmplItem;
@property (atomic, strong) NSArray *faceAnalyzers;
@property (nonatomic, weak) id<MCFilterDelegate> delegate;

// 检测当前人脸中是否有任一人脸达成模版配置的表情动作，并且触发提示回调
- (MCFaceStat)currentFaceStat;
// 检测指定人脸是否达成模版配置的表情动作，不会触发提示回调
- (MCFaceStat)singleFaceStat:(AnalyzingFaceManager *)faceAnalyzer;
// 检测指定的多个人脸中是否有任一人脸达成模版配置的表情动作
- (MCFaceStat)anyFaceStat:(NSArray *)faceAnalyzers withTips:(BOOL)showTips;

- (void) ShowGuideIfNeeded;

- (void) setupEnviroment:(NSString *)resourceFolder;

@end
