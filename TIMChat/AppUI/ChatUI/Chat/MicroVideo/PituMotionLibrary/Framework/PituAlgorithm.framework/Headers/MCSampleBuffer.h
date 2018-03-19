//
//  MCSampleBuffer.h
//  PituMotionDemo
//
//  Created by billwang on 16/5/30.
//  Copyright © 2016年 Pitu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

@interface MCSampleBuffer : NSObject

@property (nonatomic, readonly) CMSampleBufferRef sampleBuffer;
@property (nonatomic, readonly) BOOL freeDataWhenDealloc;

- (id)initWithSampleBuffer:(CMSampleBufferRef)sampleBuffer freeDataWhenDealloc:(BOOL)freeDataWhenDealloc;

@end
