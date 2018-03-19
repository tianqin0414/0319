//
//  MCFaceOffFilter.h
//  ttpic
//
//  Created by peicheng on 16/5/5.
//  Copyright © 2016年 Tencent. All rights reserved.
//

#import "MCBaseFilter.h"
#import "MCCommonFilter.h"


@interface MCFaceOffFilter : MCBaseFilter
{
    GLint filterTextureCoordinateAttribute2;
}
- (id)initWithVertexShaderFromFile:(NSString *)vertexPath fragmentShaderFromFile:(NSString *)fragmentPath;
- (void) setupFaceOffEnvironment:(NSString *)resourceFolder withImage: (UIImage *) image featurePoints: (NSArray *) featurePoints;
- (BOOL) hasValidmaterialTexture;

@end
