//
//  MCFaceDetectFilter.h
//  ttpic
//
//  Created by billwang on 16/3/11.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import "GPUImageFilter.h"

@protocol MCFaceDetectFilterDelegate <NSObject>

@optional
- (void)MCFaceDetectImageProcessed;

@end

@interface MCFaceDetectFilter : GPUImageFilter

@property (nonatomic, assign) CGSize pixelBufferSize;
@property (nonatomic, weak) id<MCFaceDetectFilterDelegate> delegate;

@end
