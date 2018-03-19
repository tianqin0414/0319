//
//  MotionCamera.h
//  MotionCamera
//
//  Created by billwang on 16/5/10.
//  Copyright © 2016年 Pitu. All rights reserved.
//

#import <PituAlgorithm/AnalyzingFaceManager.h>
#import <PituAlgorithm/MCBaseFilter.h>
#import <PituAlgorithm/MCCommonFilter.h>
#import <PituAlgorithm/MCCustomFilter.h>
#import <PituAlgorithm/MCDeformFilter.h>
#import <PituAlgorithm/MCCVSFilter.h>
#import <PituAlgorithm/MCFaceOffFilter.h>
#import <PituAlgorithm/MCMeshFilter.h>
#import <PituAlgorithm/MCFilterProvider.h>
#import <PituAlgorithm/MCFaceDetectFilter.h>
#import <PituAlgorithm/MCTmplElement.h>
#import <PituAlgorithm/MCTmplItem.h>
#import <PituAlgorithm/MCSampleBuffer.h>
#import <PituAlgorithm/MCOrientationFilter.h>
#import <PituAlgorithm/MCDataOutput.h>
#import <PituAlgorithm/MCMovieWriter.h>

@interface MotionCamera : NSObject

+ (NSString *)sdkVersion;

@end
