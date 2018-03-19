//
//  ImageProvider.h
//  FilterShowcase
//
//  Created by apple on 12-5-11.
//  Copyright (c) 2012年 Cell Phone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HFUIImage.h"
#import "GPUImageOutput.h"

@interface ImageProvider : GPUImageOutput
{
    int imageWidth;
    int imageHeight;
}

- (void)openImageWithURL:(NSURL *)url;
- (void)openImage:(UIImage *)image;
- (void)openHFImage:(HFUIImage *)image;
- (void)openInternImage:(struct _Image *)image;
- (void)changeFilter;

@end

@interface ImageProviderNearest : ImageProvider

@end