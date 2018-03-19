//
//  FilterFactory.h
//  PituAlgorithm
//
//  Created by Patrick Yang on 16/2/22.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GPUImageFilter.h"
#import "CPUImageFilter.h"

@interface FilterFactory : NSObject

@property (nonatomic, strong) NSString *bundleDirctory;
@property (nonatomic, assign) BOOL debugAssertForRunInFilterQueue;

+ (FilterFactory *)shareFactory;

+ (dispatch_queue_t)filterQueue;
+ (void)runBlockInFilterQueueSync:(dispatch_block_t)block;
+ (void)runBlockInFilterQueueAsync:(dispatch_block_t)block;
+ (BOOL)isUsingFilterEngine;// DEFAULT:YES, TODO
+ (void)setUsingFilterEngine:(BOOL)use;
+ (void)freezeGPU;
+ (void)unfreezeGPU;

+ (CPUImageFilter *)createCPUFilter:(int)filterId;
+ (GPUImageFilter *)createGPUFilter:(int)filterId;
+ (GPUImageFilter *)createGPUFilter:(NSString *)filterId withIndex:(NSInteger)index;

+ (BOOL)isCPUFilter:(int)filterId;
+ (BOOL)isCPUParameterAdjust:(int)filterId;
+ (BOOL)isAlphaParameterAdjust:(int)filterId;
+ (int)isMultiParameter:(int)filterId;
+ (BOOL)canSaveForBigPhoto:(int)filterId;
+ (int)filterIdFromString:(NSString *)string effectIndex:(NSInteger)index;

+ (BOOL)supportUIImageSize:(CGSize)size;
UIImage *HefeiApplyGPUFilter(NSString *filterId, NSInteger effectIndex, CGFloat param, UIImage *image);
@end
