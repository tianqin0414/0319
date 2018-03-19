//
//  MCMeshFilter.h
//  ttpic
//
//  Created by peicheng on 16/5/18.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import "MCBaseFilter.h"
#import "MCCommonFilter.h"

@interface MCMeshFilter : MCBaseFilter

- (id)initWithVertexShaderFromFile:(NSString *)vertexPath fragmentShaderFromFile:(NSString *)fragmentPath;

@end
