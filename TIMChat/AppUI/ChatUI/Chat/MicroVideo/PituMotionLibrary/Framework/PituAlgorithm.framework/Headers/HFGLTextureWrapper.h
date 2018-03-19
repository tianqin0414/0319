//
//  HFGLTextureWrapper.h
//  FilterEngine
//
//  Created by Patrick Yang on 15/1/21.
//  Copyright (c) 2015年 Tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <FilterEngine/HFFilterConfig.h>

struct _Image;

@interface HFGLTextureWrapper : NSObject

@property (nonatomic, assign) GLuint glTexture;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) HFGLTextureOptions options;

+ (HFGLTextureOptions)defaultOptions;

+ (HFGLTextureWrapper *)textureWithSize:(CGSize)size;
+ (HFGLTextureWrapper *)textureWithImageName:(NSString *)name;
+ (HFGLTextureWrapper *)textureWithImageName:(NSString *)name bundlePath:(NSString *)bundlePath;
+ (HFGLTextureWrapper *)textureWithImage:(struct _Image *)image;
+ (HFGLTextureWrapper *)textureWithUIImage:(UIImage *)image;
+ (HFGLTextureWrapper *)textureWithLuminance:(char *)data size:(CGSize)size;

- (void)resetTexture;
- (void)updateImage:(struct _Image *)image;
- (void)updateLuminance:(char *)data size:(CGSize)size;

@end
