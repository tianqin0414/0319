//
//  HFGLFrameBufferWrapper.h
//  FilterEngine
//
//  Created by Patrick Yang on 15/3/25.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HFGLTextureWrapper.h"

@interface HFGLFrameBufferWrapper : NSObject

@property (nonatomic, assign) GLuint glFrameBuffer;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, strong) HFGLTextureWrapper *texture;

- (void)bindTexture:(HFGLTextureWrapper *)texture;
- (void)activeFBO;

@end
