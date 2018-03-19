//
//  MCCommonVertexShader.h
//  ttpic
//
//  通用顶点shader
//  common vertex shader
//
//  Created by dreamqian on 16/4/11.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import "MCCommonFilter.h"

@interface MCCVSFilter : MCBaseFilter

- (id)initWithVertexShaderFromFile:(NSString *)vertexPath fragmentShaderFromFile:(NSString *)fragmentPath;

@end
