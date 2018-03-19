//
//  MCCustomFilter.h
//  ttpic
//
//  Created by billwang on 16/3/8.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import "MCCommonFilter.h"


@interface MCCustomFilter : MCBaseFilter

- (id)initWithVertexShaderFromFile:(NSString *)vertexPath fragmentShaderFromFile:(NSString *)fragmentPath;

@end


@interface MCCustomFilterPreprocess : MCCustomFilter

@property (nonatomic, strong) MCCommonFilter *commonFilter;

@end


@interface MCCustomFilterPostprocess : MCCommonFilter

@property (nonatomic, strong) MCCustomFilter *customFilter;

- (id)initWithVertexShaderFromFile:(NSString *)vertexPath fragmentShaderFromFile:(NSString *)fragmentPath;

@end
