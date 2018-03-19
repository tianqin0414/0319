//
//  UIImageOrientationFilter.h
//  MyCam
//
//  Created by Patrick Yang on 13-7-25.
//  Copyright (c) 2013年 Microrapid. All rights reserved.
//

#import "GPUImageFilter.h"

typedef enum {
    UIImageFormatRGBA = 0,
    UIImageFormat420V,
    UIImageFormat420F,
    UIImageFormatBGRA,
    UIImageFormatARGB,
    UIImageFormatCount
}UIImageFormat;

@interface UIImageOrientationFilter : GPUImageFilter

@property (nonatomic, assign) CGSize pixelBufferSize;

- (void)setInputImage:(UIImage *)image;
- (void)setInputPixelBuffer:(CVPixelBufferRef)buffer withFormat:(int)format;

@end

@interface RGB2YUV420Filter : GPUImageFilter

@end

@interface YUV4202RGBFilter : GPUImageFilter

@end

@interface RGB2YUV420OneFilter : GPUImageFilter

@end
