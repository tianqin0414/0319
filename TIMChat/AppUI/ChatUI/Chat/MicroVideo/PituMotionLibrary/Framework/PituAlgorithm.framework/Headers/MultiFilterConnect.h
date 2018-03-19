//
//  MultiFilterConnect.h
//  GPUImage
//
//  Created by 凯 郭 on 12-8-21.
//  Copyright (c) 2012年 Brad Larson. All rights reserved.
//

#import "GPUImageFilter.h"

@interface InputOutputPair : NSObject
{
    int output;
    int input;
    int index;
}
-(id) initWithOutput:(int)o andInput:(int)i andIndex:(int)ind;
-(int) getOutput;
-(int) getInput;
-(int) getIndex;
@end

@interface MultiFilterConnect : GPUImageFilter
{
    NSMutableArray *arrays;
    NSMutableArray *PairArrays;
}

- (id)init;
- (void)NewFilter;
- (void)cleanFilter;
-(void)setOutput:(int) outputIndex forInput:(int) inputIndex forIndex:(int)index;
-(void)addFilter:(GPUImageFilter*)filter;
-(int)filterCount;

@end

@interface MultiFilterConnectNearest : MultiFilterConnect

@end

